#include "../include/ui.h"
#include "../include/todo.h"

int main() 
{
	todo_init();        /* Load todos from file */
	ui_init();          /* Initialize ncurses */
	ui_main_loop();     /* Enter UI loop */
	ui_cleanup();       /* Exit ncurses mode */
	todo_save();        /* Save todos to file */
	return 0;
}
