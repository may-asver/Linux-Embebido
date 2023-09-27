#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>

#define PCM_DEVICE "plughw:1"
#define CHANNELS 2
#define RATE 48000
#define FRAMES 768

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    char *audio_file = argv[1];

    // Initialize ALSA
    snd_pcm_t *handle;
    if (snd_pcm_open(&handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0) < 0) {
        fprintf(stderr, "Error opening PCM device %s\n", PCM_DEVICE);
        return 1;
    }

    // Set the desired audio parameters
    snd_pcm_hw_params_t *params;
    snd_pcm_hw_params_alloca(&params);
    snd_pcm_hw_params_any(handle, params);
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_channels(handle, params, CHANNELS); // Stereo
    unsigned int sample_rate = RATE;
    snd_pcm_hw_params_set_rate_near(handle, params, &sample_rate, 0);

    if (snd_pcm_hw_params(handle, params) < 0) {
        fprintf(stderr, "Error setting hardware parameters\n");
        return 1;
    }

    // Open the audio file for reading
    FILE *file = fopen(audio_file, "rb");
    if (!file) {
        fprintf(stderr, "Error opening audio file: %s\n", audio_file);
        return 1;
    }

    // Read and play the audio data
    int size = FRAMES * CHANNELS * sizeof(uint32_t);
    char *buffer = malloc(FRAMES * CHANNELS * sizeof(uint32_t));

    while (fread(buffer, 1, size, file) == size) {
        snd_pcm_sframes_t frames = snd_pcm_writei(handle, buffer, FRAMES);
        if (frames < 0) {
            frames = snd_pcm_recover(handle, frames, 0);
        }
    }

    // Close the audio file and cleanup
    fclose(file);
    snd_pcm_drain(handle);
    snd_pcm_close(handle);

    return 0;
}


