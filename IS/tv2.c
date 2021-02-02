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
    l = 0,
    *recorded_index,
    memory = 0,
    seconds_in_day = 86400,
    full_time = 0,
    recording = 0,
    seen = 0,
    watching = 0,
    sum = 0,
    start = 0,
    time = 0,
    end = 0;
    char data[] = "data_tv.txt";
    char res[] = "res_tv.txt";
    FILE *fr;
    FILE *fw;
    fr = fopen(data, "r");
    if(NULL == fr) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }
    fscanf (fr, "%lld %lld %lld", &n, &v, &k);
    struct show *oneShow = calloc(n, sizeof(struct show));
    recorded_index = calloc (n, sizeof(long long));
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
    fw = fopen(res, "w");
    if(NULL == fw) {
        printf("Error! Could not create results file.\nProgram terminated.\n");
        fclose(fr);
        return 0;
    }
    if(full_time > seconds_in_day) {
        fprintf(fw, "NEGALIMA");
        fclose(fw);
        printf("Program ended.\nYou can find results in file %s\n", res);
        return 0;
    }
    time = oneShow[0].start;
    //einu per laidas, jeigu neziurima, pradedu ziuret
    while(seen != n) {
        for(int i = 0; i < n; ++i) {
            if(oneShow[i].start < time && oneShow[i].recorded == 0 && oneShow[i].watched == 0) {
                printf("Show %d is being recorded\n", i);
                oneShow[i].recorded += time - oneShow[i].start;
                //++recording;
                recorded_index[l] = i;
                memory += oneShow[i].recorded;
                //printf("Show %d is being recorded\n", i);
                
                /*if(oneShow[i].recorded == oneShow[i].time) {
                    --recording;
                    memory -= oneShow[i].recorded;
                }*/
                /*if(recording > k || memory > v){
                    fprintf(fw, "NEGALIMA");
                    fclose(fw);
                    free(oneShow);
                    printf("Program ended.\nYou can find results in file %s\n", res);
                    return 0;
                }*/
            }
            //cia kazkas negerasi
            /*
            if (oneShow[i].start >= time){
                if(oneShow[i].recorded < oneShow[i].time - oneShow[i].watched) {
                    oneShow[i].watched = oneShow[i].recorded;
                    time += oneShow[i].recorded;
                    oneShow[i].recorded = 0;
                } else {
                    time = oneShow[i].end;
                    oneShow[i].watched = oneShow[i].time;
                    ++seen;
                }
            } 
            */
            else if (oneShow[i].start == time){
                printf("Show %d is being watched\n", i);
                time = oneShow[i].end;
                oneShow[i].watched = oneShow[i].time;
                ++seen;
            } 

            else if (oneShow[i].recorded != 0 && oneShow[i].watched != oneShow[i].time){
                for(int ii = 0; ii < l; ++ii) {
                    printf("Show %d is being watched from a recording\n", i);
                    int index = recorded_index[ii];
                    oneShow[index].watched += oneShow[index].recorded;
                    time = oneShow[index].recorded;
                }
            }
        }
    }
    fprintf(fw, "%lld", time);
    free(oneShow);
    fclose(fw);
    printf("Program ended.\nYou can find results in file %s\n", res);
    return 0;
}
