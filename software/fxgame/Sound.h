#ifndef SOUND_H_
#define SOUND_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <altera_up_avalon_audio_and_video_config.h>
#include <altera_up_avalon_audio.h>
#include <altera_up_avalon_audio_regs.h>
#include <sys/alt_irq.h>

#define SIZE 10240

typedef short int wav;

//Sound buffer object
typedef struct {
    int read;   //index where data starts reading
    int write;  //index where data can be written
    alt_up_audio_dev *audio;
    short int *mix;     //output sound data
    short int *alive;
    short int *death;
    short int *drop;
    short int *end;
    short int *explode;
    short int *powerup;
    short int *start;
    short int *bg;
    wav fp;
} SoundBuffer;

void initSound(SoundBuffer *sb);
void initSoundFX(SoundBuffer *sb);
int initSoundBG(SoundBuffer *sb);
void initSoundFinal(SoundBuffer *sb);
void refreshSoundBG(SoundBuffer *sb);

#endif