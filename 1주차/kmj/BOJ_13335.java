import java.util.*;
import java.io.*;

public class BOJ_13335 {

    private static int N;
    private static int MAX_LENGTH;
    private static int MAX_WEIGHT;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        MAX_LENGTH = Integer.parseInt(st.nextToken());
        MAX_WEIGHT = Integer.parseInt(st.nextToken());

        int[] trucks = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            trucks[i] = Integer.parseInt(st.nextToken());
        }

        Deque<Truck> bridge = new LinkedList<>();
        int time = 0;
        int nowWeight = 0;
        int nextIndex = 0;

        while(!bridge.isEmpty() || nextIndex < N) {
            time++;

            if (!bridge.isEmpty() && bridge.peekFirst().canGoOut(time)) {
                Truck leavingTruck = bridge.removeFirst();
                nowWeight -= leavingTruck.weight;
            }

            if (nextIndex < N && nowWeight + trucks[nextIndex] <= MAX_WEIGHT && bridge.size() < MAX_LENGTH) {
                bridge.addLast(new Truck(trucks[nextIndex], time));
                nowWeight += trucks[nextIndex];
                nextIndex++;
            }
        }

        System.out.println(time);
    }

    private static class Truck {
        int weight;
        int startTime;

        public Truck(int weight, int startTime) {
            this.weight = weight;
            this.startTime = startTime;
        }

        public boolean canGoOut(int time) {
            return time - startTime >= MAX_LENGTH;
        }
    }
}
