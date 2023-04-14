// Round Robin
// 4
// 0 5
// 1 4
// 2 2
// 4 1
// 2
#include <stdio.h>
int main(){
    int cnt, j, n, t, remain, flag = 0, tq;
    int wt = 0, tat = 0, at[10], bt[10], rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d", &n);
    remain = n;
    for (cnt = 0; cnt < n; cnt++){
        printf("Enter AT and BT for Process %i :", cnt + 1);
        scanf("%i", &at[cnt]);
        scanf("%i", &bt[cnt]);
        rt[cnt] = bt[cnt];
    }
    printf("Time Quantum:\t");
    scanf("%i", &tq);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (t = 0, cnt = 0; remain != 0;){
        if (rt[cnt] <= tq && rt[cnt] > 0){
            t += rt[cnt];
            rt[cnt] = 0;
            flag = 1;
        }
        else if (rt[cnt] > 0){
            rt[cnt] -= tq;
            t += tq;
        }
        if (rt[cnt] == 0 && flag == 1){
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", cnt + 1, t - at[cnt], t - at[cnt] - bt[cnt]);
            wt += t - at[cnt] - bt[cnt];
            tat += t - at[cnt];
            flag = 0;
        }
        if (cnt == n - 1)
            cnt = 0;
        else if (at[cnt + 1] <= t)
            cnt++;
        else
            cnt = 0;
    }
    printf("\nAvg WT= %f\n", wt * 1.0 / n);
    printf("Avg TAT = %f", tat * 1.0 / n);
    return 0;
}
