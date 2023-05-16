import java.util.Scanner;

public class sjf {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of processes: ");
        int n = input.nextInt();
        int[][] Time = new int[n][6];
        // 0 => ID
        // 1 => Arrival Time
        // 2 => Burst Time
        // 3 => Completion
        // 4 => Turn around Time
        // 5 => Waiting Time
        float avgTAT = 0;
        float avgWT = 0;
        for (int i = 0; i < n; i++) {
            Time[i][0] = i;
            System.out.print("AT" + i + " ");
            Time[i][1] = input.nextInt();
            System.out.print("BT" + i + " ");
            Time[i][2] = input.nextInt();
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp, temp1, temp2;
                if (Time[i][1] > Time[j][1]) {
                    temp1 = Time[i][1];
                    Time[i][1] = Time[j][1];
                    Time[j][1] = temp1;
                    temp = Time[i][0];
                    Time[i][0] = Time[j][0];
                    Time[j][0] = temp;
                    temp2 = Time[i][2];
                    Time[i][2] = Time[j][2];
                    Time[j][2] = temp2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp, temp1, temp2;
                if (Time[i][1] == Time[j][1]) {
                    temp1 = Time[i][1];
                    Time[i][1] = Time[j][1];
                    Time[j][1] = temp1;
                    temp = Time[i][0];
                    Time[i][0] = Time[j][0];
                    Time[j][0] = temp;
                    temp2 = Time[i][2];
                    Time[i][2] = Time[j][2];
                    Time[j][2] = temp2;
                }
            }
        }
        
    }
}
