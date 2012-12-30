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

#ifndef _EDIFY_BUILTINS_H_
#define _EDIFY_BUILTINS_H_
#define EDIFY_API_VERSION_1 1
#define EDIFY_API_VERSION_2 2
#define EDIFY_API_VERSION_3 3
#define EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED -1
#define ARRAYSIZE(a) ((int)(sizeof(a) / sizeof(*(a))))
static struct edify_function {
		char * name;
		int min_argument_count;
		int max_argument_count;
		int api_version;
} edify_functions[]  = { 
	{"mount", 						4,4,											EDIFY_API_VERSION_2},
    {"is_mounted", 					1,1,											EDIFY_API_VERSION_2},
    {"unmount", 					1,1,											EDIFY_API_VERSION_2},
    {"format", 						5,5,											EDIFY_API_VERSION_2},
    {"show_progress", 				2,2,											EDIFY_API_VERSION_2},
    {"set_progress", 				1,1,											EDIFY_API_VERSION_2},
    {"delete", 						1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"delete_recursive", 			1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"package_extract_dir", 		2,2,											EDIFY_API_VERSION_2},
    {"package_extract_file", 		1,2,											EDIFY_API_VERSION_2},
    {"symlink", 					2,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"set_perm", 					4,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"set_perm_recursive", 			5,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"getprop", 					1,1,											EDIFY_API_VERSION_2},
    {"file_getprop", 				2,2,											EDIFY_API_VERSION_2},
    {"write_raw_image", 			2,2,											EDIFY_API_VERSION_2},
    {"apply_patch", 				6,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"apply_patch_check", 			1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"apply_patch_space", 			1,1,											EDIFY_API_VERSION_2},
    {"read_file", 					1,1,											EDIFY_API_VERSION_2},
    {"sha1_check", 					1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"wipe_cache", 					0,0,											EDIFY_API_VERSION_2},
    {"ui_print", 					1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2},
    {"run_program", 				1,EDIFY_FUNCTION_ARGUMENT_COUNT_UNLIMTED,		EDIFY_API_VERSION_2}};
static const int edify_function_count = ARRAYSIZE(edify_functions);

void RegisterInstallFunctions();

// SOME CHEEKY HELPERS - MAKE THE CODE MORE READABLE
#define EDIFY_FUNCTION_NAME edify_functions[function_index].name
#define EDIFY_FUNCTION_MIN_ARGC edify_functions[function_index].min_argument_count
#define EDIFY_FUNCTION_MAX_ARGC edify_functions[function_index].max_argument_count


#endif
