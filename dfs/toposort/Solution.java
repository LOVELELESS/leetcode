import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCourses = sc.nextInt();
        int m = sc.nextInt();
        int[][] prereq = new int[m][2];
        for (int i = 0; i < m; i++) {
            int first = sc.nextInt();
            int second = sc.nextInt();
            int[] pair = new int[2];
            pair[0] = first;
            pair[1] = second;
            prereq[i] = pair;
            System.out.println(first + " " + second);
        }
        Solution solution = new Solution();
        solution.findOrder(numCourses, prereq);
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, ArrayList<Integer>> adjList = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            adjList.put(i, new ArrayList<>());
        }

        for (int i = 0; i < prerequisites.length; i++) {
            int[] pair = prerequisites[i];
            // pair[1] -> pair[0]
            adjList.get(pair[1]).add(pair[0]);
        }

        LinkedList<Integer> topo = new LinkedList<>();
        HashSet<Integer> seen = new HashSet<>();
        LinkedList<Integer> stack = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (!seen.contains(i)) {
                if (!dfs(adjList, seen, stack, topo, i)) {
                    return new int[0];
                } ;
            }
        }

        int[] res = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            res[i] = topo.pollFirst();
            //System.out.println(res[i]);
        }
        return res;
    }

    public boolean dfs(HashMap<Integer, ArrayList<Integer>> adjList, HashSet<Integer> seen,
            LinkedList<Integer> stack, LinkedList<Integer> topo, int i) {
        seen.add(i);
        stack.push(i);
        System.out.println("i: " + i);
        for (int nei : adjList.get(i)) {
            if (!seen.contains(i)) {
                if (!dfs(adjList, seen, stack, topo, nei)) {
                    return false;
                }
            } else if (stack.contains(nei)) {
                return false;
            }
        }
        stack.pop();
        topo.addFirst(i);
        System.out.println(topo);
        return true;
    }
}
