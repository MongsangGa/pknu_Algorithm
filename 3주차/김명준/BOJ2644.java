import java.util.*;
import java.io.*;

//실버 2 촌수 계산
class BOJ2644 {
    private static int startNode, target;
    private static boolean[] visited;
    private static int answer;
    private static Map<Integer, List<Integer>> nodes;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        nodes = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            nodes.put(i, new ArrayList<>());
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        startNode = Integer.parseInt(st.nextToken());
        target = Integer.parseInt(st.nextToken());

        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            nodes.get(start).add(end);
            nodes.get(end).add(start);
        }

        visited = new boolean[N + 1];
        answer = -1;

        Deque<Integer> queue = new LinkedList<>();
        queue.addLast(startNode);
        visited[startNode] = true;
        int generation = 0;

        while (!queue.isEmpty() && answer == -1) {
            generation++;
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                int now = queue.removeFirst();

                if (target == now) {
                    answer = generation - 1;
                    break;
                }

                for (int next : nodes.get(now)) {
                    if (visited[next]) continue;

                    visited[next] = true;
                    queue.add(next);
                }
            }
        }

        System.out.println(answer);
    }
}
