// all preemptive CPU Scheduling
// by Anon Anderson
#include<stdio.h>
struct priority_scheduling{
    char process_name;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};
void priority(){
    int number_of_process;
    int total = 0;
    struct priority_scheduling temp_process;
    int ASCII_number = 65;
    int position;
    float average_waiting_time;
    float average_turnaround_time;
    printf("Enter the total number of Processes: ");
    scanf("%i", &number_of_process);
    struct priority_scheduling process[number_of_process];
    printf("\nPlease Enter the  Burst Time and Priority of each process:\n");
    for (int i = 0; i < number_of_process; i++){
        process[i].process_name = (char)ASCII_number;
        printf("\nEnter the details of the process %c \n", process[i].process_name);
        printf("Enter the burst time: ");
        scanf("%d", &process[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &process[i].priority);
        ASCII_number++;
    }
    for (int i = 0; i < number_of_process; i++){
        position = i;
        for (int j = i + 1; j < number_of_process; j++){
            if (process[j].priority > process[position].priority)
                position = j;
        }
        temp_process = process[i];
        process[i] = process[position];
        process[position] = temp_process;
    }
    process[0].waiting_time = 0;
    for (int i = 1; i < number_of_process; i++){
        process[i].waiting_time = 0;
        for (int j = 0; j < i; j++)
            process[i].waiting_time += process[j].burst_time;
        total += process[i].waiting_time;
    }
    average_waiting_time = (float)total / (float)number_of_process;
    total = 0;
    printf("\n\nProcess_name \t Burst Time \t Waiting Time \t  Turnaround Time\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < number_of_process; i++){
        process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
        total += process[i].turn_around_time;
        printf("\t  %c \t\t  %d \t\t %d \t\t %d", process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
        printf("\n-----------------------------------------------------------\n");
    }
    average_turnaround_time = (float)total / (float)number_of_process;
    printf("\n\n Average Waiting Time : %f", average_waiting_time);
    printf("\n Average Turnaround Time: %f\n", average_turnaround_time);
}
void sjf(){
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%i", &limit);
    printf("\nEnter Details of %i Processes\n", limit);
    for (i = 0; i < limit; i++){
        printf("\nEnter Arrival Time:\t");
        scanf("%i", &arrival_time[i]);
        printf("Enter Burst Time:\t");
        scanf("%i", &burst_time[i]);
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for (time = 0; count != limit; time++){
        smallest = 9;
        for (i = 0; i < limit; i++){
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                smallest = i;
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0){
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;
    printf("\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:%lf\n", average_turnaround_time);
}
void rr(){
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
}
void srtf(){
    int a[10], b[10], x[10], i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
    printf("Number of Processes:");
    scanf("%i", &n);
    printf("AT :->\n");
    for (i = 0; i < n; i++)
        scanf("%i", &a[i]);
    printf("BT :->\n");
    for (i = 0; i < n; i++)
        scanf("%i", &b[i]);
    for (i = 0; i < n; i++)
        x[i] = b[i];
    b[9] = 9999;
    for (time = 0; count != n; time++){
        smallest = 9;
        for (i = 0; i < n; i++){
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;
        if (b[smallest] == 0){
            count++;
            end = time + 1;
            avg = avg + end - a[smallest] - x[smallest];
            tt = tt + end - a[smallest];
        }
    }
    printf("\nAverage waiting time = %lf\n", avg / n);
    printf("Average Turnaround time = %lf", tt / n);
}
int main(){
    int n;
    printf("PREEMPTIVE CPU SCHEDULING:-->\n1. Priority\n2. SJF\n3. Round Robin\n4. SRTF\n5. Exit\n");
    while (1){
        printf("\nEnter Choice : ");
        scanf("%i", &n);
        if (n==1)
            priority();
        else if (n==2)
            sjf();
        else if (n == 3)
            rr();
        else if (n == 4)
            srtf();
        else if (n == 5)
            break;
        else
            printf("Correct choice please....!");
    }
    return 0;
}
