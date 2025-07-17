#include <ncurses.h>
#include "../include/todo.h"

void ui_init() {
    initscr(); noecho(); cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void ui_cleanup() {
    endwin();
}

void ui_draw_header() {
    mvprintw(0, 0, " TODO - Press 'a' to add, 'd' to delete, 'q' to quit ");
    hline('-', COLS);
}

void ui_draw_footer() {
    mvprintw(LINES - 1, 0, " ↑↓ to navigate | Press 'q' to quit ");
    clrtoeol();
}

void ui_main_loop() {
    int ch;
    int selected = 0;

    while (1) {
        clear();
        ui_draw_header();

        for (int i = 0; i < todo_count(); ++i) {
            if (i == selected)
                attron(A_REVERSE);
            mvprintw(2 + i, 2, "- %s", todo_get(i));
            if (i == selected)
                attroff(A_REVERSE);
        }

        ui_draw_footer();
        refresh();

        ch = getch();
        if (ch == 'q') break;
        else if (ch == KEY_UP && selected > 0) selected--;
        else if (ch == KEY_DOWN && selected < todo_count() - 1) selected++;
        else if (ch == 'a') {
            echo();
            char buffer[256];
            mvprintw(LINES - 2, 0, "New task: ");
            getnstr(buffer, 255);
            todo_add(buffer);
            noecho();
        } else if (ch == 'd') {
            todo_delete(selected);
            if (selected >= todo_count()) selected = todo_count() - 1;
        }
    }
}

