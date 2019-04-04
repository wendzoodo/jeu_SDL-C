#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED


typedef struct Input


{
  int left, right, up, down, jump, attack, enter, erase, pause,run,esp;

} Input;

void get_input(Input *i);

#endif //INPUT_H_INCLUDED
