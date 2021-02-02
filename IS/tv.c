#include <stdio.h>
#include <stdlib.h>

struct show {
    int start,
    end,
    time,
    index,
    watching,
    recording,
    watched, 
    recorded;
};

int main() {
    long long n, //laidu sk
    v, //sekundes
    k, //irasomu laidu vienu metu
    *memory,
    seconds_in_day = 86400,
    full_time = 0,
    recording = 0,
    seen = 0,
    watching = 0,
    sum = 0;
    char data[] = "data_tv.txt";
    char res[] = "res_tv.txt";
    FILE *fr;
    FILE *fw;
    fr = fopen(data, "r");
    if(NULL == fr) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }
    fw = fopen(res, "w");
    if(NULL == fw) {
        printf("Error! Could not create results file.\nProgram terminated.\n");
        fclose(fr);
        return 0;
    }
    fscanf (fr, "%lld %lld %lld", &n, &v, &k);
    struct show *oneShow = calloc(n, sizeof(struct show));
    for(int i = 0; i < n; ++i) {
        fscanf (fr, "%lld %lld", &oneShow[i].start, &oneShow[i].end);
        oneShow[i].time = oneShow[i].end - oneShow[i].start;
        oneShow[i].index = i;
        oneShow[i].watched = 0;
        oneShow[i].recorded = 0;
        oneShow[i].recording = 0;
        oneShow[i].watching = 0;
        full_time += oneShow[i].time;
    }
    fclose(fr);

    if(full_time > seconds_in_day) {
        fprintf(fw, "NEGALIMA");
        fclose(fw);
        return 0;
    }
    memory = calloc(k, v);

    //struct show watching;

    for(int s = oneShow[0].start; s <= seconds_in_day; ++s) {
        for(int i = 0; i < n; ++i) {
            if(watching == 0 && oneShow[i].start == s && oneShow[i].time != oneShow[i].watched) { // || watching == 0 && oneShow[i].recorded >= oneShow[i].watched
                watching = 1;
                oneShow[i].watching = 1;
                ++oneShow[i].watched;
                if(oneShow[i].time == oneShow[i].watched) {
                    ++seen;
                    oneShow[i].watched = 1;
                }
            } else if(oneShow[i].start == s && oneShow[i].watching == 0) {
                ++recording;
                oneShow[i].recording = 1;
                ++oneShow[i].recorded;
            } else if(oneShow[i].recording == 1) {
                if(oneShow[i].recorded != oneShow[i].time)
                    ++oneShow[i].recorded;
                else {
                    oneShow[i].recording = 0;
                    --recording;
                }
            }
        }
        if(recording > k) {
            fprintf(fw, "NEGALIMA");
            printf("%lld", recording);
            fclose(fw);
            return 0;
        }
        if(n == seen){
            fprintf(fw, "%lld", s);
            break;
        }
    }
    if(n > seen)
        fprintf(fw, "NEGALIMA");
    printf("Program ended.\nYou can find results in file %s\n", res);
    free(oneShow);
    fclose(fw);
    return 0;
}
