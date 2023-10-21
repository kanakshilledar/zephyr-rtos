/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef SHELL_TYPES_H__
#define SHELL_TYPES_H__


#ifdef __cplusplus
extern "C" {
#endif

enum shell_vt100_color {
	SHELL_VT100_COLOR_BLACK,
	SHELL_VT100_COLOR_RED,
	SHELL_VT100_COLOR_GREEN,
	SHELL_VT100_COLOR_YELLOW,
	SHELL_VT100_COLOR_BLUE,
	SHELL_VT100_COLOR_MAGENTA,
	SHELL_VT100_COLOR_CYAN,
	SHELL_VT100_COLOR_WHITE,

	SHELL_VT100_COLOR_DEFAULT,

	VT100_COLOR_END
};

struct shell_vt100_colors {
<<<<<<< HEAD
	enum shell_vt100_color col; /* Text color. */
	enum shell_vt100_color bgcol; /* Background color. */
};

struct shell_multiline_cons {
	uint16_t cur_x;     /* horizontal cursor position in edited command line.*/
	uint16_t cur_x_end; /* horizontal cursor position at the end of command.*/
	uint16_t cur_y;     /* vertical cursor position in edited command.*/
	uint16_t cur_y_end; /* vertical cursor position at the end of command.*/
	uint16_t terminal_hei; /* terminal screen height.*/
	uint16_t terminal_wid; /* terminal screen width.*/
=======
	enum shell_vt100_color col; /*!< Text color. */
	enum shell_vt100_color bgcol; /*!< Background color. */
};

struct shell_multiline_cons {
	uint16_t cur_x;     /*!< horizontal cursor position in edited command line.*/
	uint16_t cur_x_end; /*!< horizontal cursor position at the end of command.*/
	uint16_t cur_y;     /*!< vertical cursor position in edited command.*/
	uint16_t cur_y_end; /*!< vertical cursor position at the end of command.*/
	uint16_t terminal_hei; /*!< terminal screen height.*/
	uint16_t terminal_wid; /*!< terminal screen width.*/
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	uint8_t name_len;   /*!<console name length.*/
};

struct shell_vt100_ctx {
	struct shell_multiline_cons cons;
	struct shell_vt100_colors col;
<<<<<<< HEAD
	uint16_t printed_cmd;  /* printed commands counter */
=======
	uint16_t printed_cmd;  /*!< printed commands counter */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

#ifdef __cplusplus
}
#endif

#endif /* SHELL_TYPES_H__ */
