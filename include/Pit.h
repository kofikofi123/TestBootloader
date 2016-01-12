#ifndef _PIT_H
#define _PIT_H

#define FORMATWRITEOP(control, mode, rw, bcd) ((control << 6) | (rw << 4) | (mode << 1) | bcd)

void install_pit(void);
void pit_event(void);
void reloadRegister(void);

#endif