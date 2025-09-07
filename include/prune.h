// File:        prune.h
// Project:     prune
// Repository:  https://github.com/nessbe/prune
//
// Copyright (c) 2025 nessbe
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// For more details, see the LICENSE file at the root of the project.

#ifndef PRUNE_H
#define PRUNE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pr_program {
	const char *name;
} pr_program_t;

typedef struct pr_argument {
	const char *name;
} pr_argument_t;

typedef struct pr_command_line {
	pr_program_t program;
	int argument_count;
	pr_argument_t *arguments;
} pr_command_line_t;

int main(int argc, char *argv[]);

pr_command_line_t pr_parse_command_line(int argc, char *argv[]);

int pr_main(pr_command_line_t *command_line);

#endif
