// File:        prune.c
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

#include "prune.h"

int main(int argc, char *argv[])
{
	pr_command_line_t command_line = pr_parse_command_line(argc, argv);
	pr_main(&command_line);
	return 0;
}

pr_command_line_t pr_parse_command_line(int argc, char *argv[])
{
	pr_command_line_t command_line;
	command_line.program.name = argv[0];
	command_line.argument_count = argc - 1;
	command_line.arguments = (pr_argument_t *)malloc(command_line.argument_count * sizeof(pr_argument_t));

	for (int i = 0; i < command_line.argument_count; i++) {
		command_line.arguments[i].name = argv[i + 1];
	}

	return command_line;
}

int pr_main(pr_command_line_t *command_line)
{
	printf("Program Name: %s\n", command_line->program.name);
	printf("Argument Count: %d\n", command_line->argument_count);

	for (int i = 0; i < command_line->argument_count; i++) {
		printf("Argument %d: %s\n", i + 1, command_line->arguments[i].name);
	}

	return 0;
}
