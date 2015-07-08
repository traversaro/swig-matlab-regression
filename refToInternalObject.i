/* File : example.i */
%module refToInternalObject

%{
#include "refToInternalObject.h"
%}

/* Let's just grab the original header file here */
%include "refToInternalObject.h"