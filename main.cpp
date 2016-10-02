#include <iostream>
#include <string>

#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
#endif

#include "engine.h"

#define  BUFSIZE 256

std::string GetCurrentWorkingDir() {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

int main() {

	Engine *ep;
	mxArray *result = NULL;
	char buffer[BUFSIZE+1];
	buffer[BUFSIZE] = '\0';

	/*
	 * Call engOpen with a NULL string. This starts a MATLAB process
     * on the current host using the command "matlab".
	 */
	// One may add also -nojvm, but in that case no graph will be drawn
	if (!(ep = engOpen("matlab -nosplash -nodesktop"))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return 1;
	}

	/*
	 * Job
	 */
	engOutputBuffer(ep, buffer, BUFSIZE);

	std::string addpath = "addpath('"
		+ GetCurrentWorkingDir()
		+ "')";
	engEvalString(ep, addpath.c_str());

	std::cout << "Current directory : ";
	engEvalString(ep, "pwd");
	printf("%s", buffer);

	engEvalString(ep, "r = my_function();");
	if ((result = engGetVariable(ep, "r")) == NULL)
	   	std::cout << "Oops! things went wrong" << std::endl;
	else {
	   	double z = mxGetScalar(result);
	   	std::cout << "output of function : " << z << std::endl;
	}

	/*
	 * Free memory, close MATLAB engine and exit.
	 */
	std::cout  << "Done!" << std::endl;
	mxDestroyArray(result);
	engClose(ep);

	return 0;
}
