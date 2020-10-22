import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Integer>> connections = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int first = sc.nextInt();
            int second = sc.nextInt();
            List<Integer> tmp = new ArrayList<>();
            tmp.add(first);
            tmp.add(second);
            connections.add(tmp);
        }

        Solution solution = new Solution();
        List<List<Integer>> res = solution.criticalConnections(n, connections);
        res.stream().forEach(System.out::println);
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        HashMap<Integer, Integer> start = new HashMap<>();
        HashMap<Integer, Integer> loLink = new HashMap<>();

        HashMap<Integer, ArrayList<Integer>> adjList = new HashMap<>();
        for (int i = 0; i < n; i++) {
            adjList.put(i, new ArrayList<>());
        }
        for (int i = 0; i < connections.size(); i++) {
            List<Integer> pair = connections.get(i);
            adjList.get(pair.get(0)).add(pair.get(1));
            adjList.get(pair.get(1)).add(pair.get(0));
        }

        // since connected, can start from any node, choose to start from node 0
        HashSet<Integer> seen = new HashSet<>();
        List<List<Integer>> res = new ArrayList<>();

        int clock = 0;
        dfs(adjList, seen, start, loLink, clock, 0, -1);
        for (int i = 0; i < connections.size(); i++) {
            List<Integer> pair = connections.get(i);
            //System.out.println("first: " + pair.get(0) + " start: " + start.get(pair.get(0))
            //        + " lo: " + loLink.get(pair.get(0)));
            //System.out.println("second: " + pair.get(1) + " start: " + start.get(pair.get(1))
            //        + " lo: " + loLink.get(pair.get(1)));
            if (start.get(pair.get(0)) < loLink.get(pair.get(1))
                    || start.get(pair.get(1)) < loLink.get(pair.get(0))) {
                // found a bridge
                res.add(pair);
            }
        }

        return res;
    }

    public int dfs(HashMap<Integer, ArrayList<Integer>> adjList, HashSet<Integer> seen,
            HashMap<Integer, Integer> start, HashMap<Integer, Integer> loLink, int clock, int src,
            int parent) {
        //System.out.println("start: " + src);
        seen.add(src);

        clock += 1;
        start.put(src, clock);
        //System.out.println("assign start of " + src + " : " + clock);
        int lo = clock;
        loLink.put(src, lo);

        for (int nei : adjList.get(src)) {
            //System.out.println("nei: " + nei);
            if (!seen.contains(nei)) {
                clock = dfs(adjList, seen, start, loLink, clock, nei, src);
                lo = Math.min(lo, loLink.get(nei));
            } else if (nei != parent) {
                lo = Math.min(lo, loLink.get(nei));
                //System.out.println("in " + src + ", lo : " + lo);
            }

            //System.out.println(loLink);
        }

        loLink.replace(src, lo);
        //System.out.println("assign lo " + src + " : " + lo);
        //System.out.println("end: " + src);
        return clock;
    }

}
