/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//##include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "edify_checker.h"
#include "edify/expr.h"
#include "builtins.h"

int is_registered_function(const char* test_string){
	int counter = 0 ; int function_index = -1 ; int test_strlen = strlen(test_string) ;
	for(counter = 0 ; counter < edify_function_count ; counter++){
		int function_name_strlength = strlen(edify_functions[counter].name) ;
		int compare_length =  function_name_strlength > test_strlen ?  function_name_strlength : test_strlen ;
		int strc = strncmp(edify_functions[counter].name,test_string,compare_length);
		if(!strc){
			function_index = counter;
			break;				
		}
	}
	return function_index;
}

int check_argument_count(int function_index,State* state,int argc){
	if((argc) & (!EDIFY_FUNCTION_MIN_ARGC)){
		ErrorAbort(state, "%s() expects no args, got %d", EDIFY_FUNCTION_NAME, argc);
		return 0;
	}
	
	if(EDIFY_FUNCTION_MIN_ARGC == EDIFY_FUNCTION_MAX_ARGC){
		
		if(argc != EDIFY_FUNCTION_MIN_ARGC){
		   ErrorAbort(state, "%s() expects %d args, got %d", EDIFY_FUNCTION_NAME,EDIFY_FUNCTION_MIN_ARGC, argc);
		   return 0;
		}
	}
	if(EDIFY_FUNCTION_MIN_ARGC != EDIFY_FUNCTION_MAX_ARGC){
			
			if((argc < EDIFY_FUNCTION_MIN_ARGC)){
				if(EDIFY_FUNCTION_MAX_ARGC == EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED){
					if(EDIFY_FUNCTION_MIN_ARGC == 1)
						ErrorAbort(state, "%s() expects at least %d arg, got %d", EDIFY_FUNCTION_NAME,	EDIFY_FUNCTION_MIN_ARGC,argc);
					else if(EDIFY_FUNCTION_MIN_ARGC > 1)
						ErrorAbort(state, "%s() expects at least %d args, got %d", EDIFY_FUNCTION_NAME,	EDIFY_FUNCTION_MIN_ARGC,argc);
				}else if(argc > EDIFY_FUNCTION_MAX_ARGC ){
					 ErrorAbort(state, "%s() expects between %d and %d args, got %d", EDIFY_FUNCTION_NAME,	EDIFY_FUNCTION_MIN_ARGC,	EDIFY_FUNCTION_MAX_ARGC,argc);
				}
				return 0;
			}
	}
	return 1;
}
Value* GlobalFn(const char* name, State* state, int argc, Expr* argv[]) {
	
	// get the function index, 
	int function_index = is_registered_function(name);
	if( function_index==-1){
		ErrorAbort(state, "ARRRRG: EDIFY CHECKER PROGRAM ERROR - SOME ONES FUCKED UP\nFunction %s is registered but is not setup in local function table\n", name);
		return NULL;
	}
	if(!check_argument_count(function_index,state,argc))
		return NULL;
	
	
	//fprintf(stdout,"%s %d\n",name,function_index); 
	return StringValue(strdup(""));
}
void RegisterInstallFunctions() {
    RegisterFunction("mount", GlobalFn);
    RegisterFunction("is_mounted", GlobalFn);
    RegisterFunction("unmount", GlobalFn);
    RegisterFunction("format", GlobalFn);
    RegisterFunction("show_progress", GlobalFn);
    RegisterFunction("set_progress", GlobalFn);
    RegisterFunction("delete", GlobalFn);
    RegisterFunction("delete_recursive", GlobalFn);
    RegisterFunction("package_extract_dir", GlobalFn);
    RegisterFunction("package_extract_file", GlobalFn);
    RegisterFunction("symlink", GlobalFn);
    RegisterFunction("set_perm", GlobalFn);
    RegisterFunction("set_perm_recursive", GlobalFn);

    RegisterFunction("getprop", GlobalFn);
    RegisterFunction("file_getprop", GlobalFn);
    RegisterFunction("write_raw_image", GlobalFn);

    RegisterFunction("apply_patch", GlobalFn);
    RegisterFunction("apply_patch_check", GlobalFn);
    RegisterFunction("apply_patch_space", GlobalFn);

    RegisterFunction("read_file", GlobalFn);
    RegisterFunction("sha1_check", GlobalFn);

    RegisterFunction("wipe_cache", GlobalFn);

    RegisterFunction("ui_print", GlobalFn);

    RegisterFunction("run_program", GlobalFn);
}
