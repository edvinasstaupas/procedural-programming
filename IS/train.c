#include <stdio.h>
#include <stdlib.h>

struct wagon {
    long long initial, 
    seated,
    standing;
};
void sk (struct wagon **onewagon, long long n, long long k, long long *sum);

int main() {
    long long n,//vagonu sk
    k,//sedimu vietu sk
    initial_sum = 0,//pradine suma
    sum = 0;//visi perejimai
    char data[] = "data_train.txt";
    char res[] = "res_train.txt";
    FILE *fr;
    FILE *fw;
    fr = fopen(data, "r");
    if(NULL == fr) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }
    fscanf (fr, "%lld %lld", &n, &k);
    struct wagon *oneWagon = malloc (n * sizeof(struct wagon));
    for(int i = 0; i < n; ++i) {
        fscanf (fr, "%lld", &oneWagon[i].initial); 
        initial_sum += oneWagon[i].initial;
    }
    fclose(fr);
    if(initial_sum != n*k) {
        printf("Error! Wrong input.\nProgram terminated.\n");
        fclose(fw);
        return 0;
    }
    sk(&oneWagon, n, k, &sum);
    fw = fopen(res, "w");
    if(NULL == fw) {
        printf("Error! Could not create results file.\nProgram terminated.\n");
        return 0;
    }
    fprintf(fw, "%lld\n", sum);
    printf("Program ended.\nYou can find results in file %s\n", res);
    free(oneWagon);
    fclose(fw);
    return 0;
}

void sk (struct wagon **oneWagon, long long n, long long k, long long *sum){
    for(int i = 0; i < n; ++i) {
        if(oneWagon[i]->initial <= k) {
            oneWagon[i]->seated = oneWagon[i]->initial;
            oneWagon[i]->standing = 0;
        }
        else {
            oneWagon[i]->seated = k;
            oneWagon[i]->standing = oneWagon[i]->initial - k;
        }
    }

    for(int i = 0; i < n-1; ++i) {
        int temp;
        if(oneWagon[i]->seated < k) {
            for(int ii = i+1; ii < n; ++ii){
                if(oneWagon[ii]->standing > 0){
                    if(oneWagon[ii]->standing + oneWagon[i]->seated <= k) {
                        temp = oneWagon[ii]->standing;
                        oneWagon[i]->seated += oneWagon[ii]->standing;
                        *sum += (ii - i) * temp;
                    } else {
                        temp = k - oneWagon[i]->seated;
                        oneWagon[i]->seated += temp;
                        oneWagon[ii]->standing -=temp;
                        *sum += (ii - i) * temp;
                        break;
                    }
                }
            }
        } else if (oneWagon[i]->seated == k && oneWagon[i]->standing > 0) {
            for(int ii = i+1; ii < n; ++ii){
                if (oneWagon[i]->standing == 0)
                    break;
                if(oneWagon[ii]->seated < k){
                    if(oneWagon[i]->standing + oneWagon[ii]->seated <= k) {
                        temp = oneWagon[i]->standing;
                        oneWagon[ii]->seated += temp;
                        oneWagon[i]->standing = 0;
                        *sum += (ii - i) * temp;
                    } else {
                        temp = k - oneWagon[ii]->seated;
                        oneWagon[ii]->seated += temp;
                        oneWagon[i]->standing -=temp;
                       *sum += (ii - i) * temp;
                    }
                }
            }
        }
    }
}