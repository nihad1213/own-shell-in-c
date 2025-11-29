/**
 * @file commands.h
 * @brief Header for shell command handlers (exit, cd, etc.)
 */

#ifndef COMMANDS_H
#define COMMANDS_H

int handleExitCommand(void);
int handleCdCommand(const char *path);
int handleMkdirCommand(const char *dirname);
int handleLsCommand(const char *path);
int handleEchoCommand(const char *text);

#endif
