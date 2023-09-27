#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <alsa/asoundlib.h>

#define CHANNELS 2
#define RATE 48000
#define FRAMES 768

int main(int argc, char * argv[]) {

    snd_pcm_t * pcm;
    snd_pcm_hw_params_t * params;
    FILE * fp = fopen( argv[1], "w" );

    int ret = snd_pcm_open( &pcm, "hw:0", SND_PCM_STREAM_CAPTURE, 0 );

    snd_pcm_hw_params_alloca( &params );
    ret = snd_pcm_hw_params_any( pcm, params );

    ret = snd_pcm_hw_params_set_access( pcm, params, SND_PCM_ACCESS_RW_INTERLEAVED );
    ret = snd_pcm_hw_params_set_format( pcm, params, SND_PCM_FORMAT_S32_LE );
    ret = snd_pcm_hw_params_set_channels( pcm, params, CHANNELS );
    int rate = RATE; // Variable rate for the API to have a poiner in case of failure of setting 48000
    ret = snd_pcm_hw_params_set_rate( pcm, params, &rate, 0 );
    ret = snd_pcm_hw_params( pcm, params );

    int size = FRAMES * CHANNELS * sizeof (uint32_t);
    char * buffer = malloc( FRAMES * CHANNELS * sizeof (uint32_t));
    for(;;){
        snd_pcm_sframes_t frames = snd_pcm_readi( pcm, (void *)buffer, FRAMES );
        int n_bytes = fwrite( buffer, 1, size, fp );
        fflush( fp);
    }

    snd_pcm_close( pcm );
    fclose( fp );

    return 0;
}