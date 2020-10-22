import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int[][] envelopes = new int[m][2];
        for (int i = 0; i < m; i++) {
            int first = sc.nextInt();
            int second = sc.nextInt();
            int[] tmp = new int[2];
            tmp[0] = first;
            tmp[1] = second;
            envelopes[i] = tmp;
        }
        Solution solution = new Solution();
        System.out.println(solution.maxEnvelopes(envelopes));
    }

    public int maxEnvelopes(int[][] envelopes) {
        int n = envelopes.length;
        ArrayList<Node> nodeList = new ArrayList<>();
        HashMap<Node, ArrayList<Node>> adjList = new HashMap<>();
        HashMap<Node, Integer> dist = new HashMap<>();

        for (int i = 0; i < n; i++) {
            Node node = new Node(envelopes[i][0], envelopes[i][1]);

            if (!adjList.containsKey(node)) {
                adjList.put(node, new ArrayList<>());
            }

            for (Node other : nodeList) {
                if (node.canFitInto(other)) {
                    // node -> other
                    adjList.get(node).add(other);
                }

                if (other.canFitInto(node)) {
                    // other -> node
                    adjList.get(other).add(node);
                }
            }
            nodeList.add(node);
        }

        //System.out.println(adjList);

        HashSet<Node> seen = new HashSet<>();
        LinkedList<Node> topo = new LinkedList<>();

        for (Node node : nodeList) {
            if (!seen.contains(node)) {
                dfs(adjList, seen, topo, null, node);
            }
            dist.put(node, -1);
        }

        System.out.println(topo);

        int maxRes = 0;
        dist.replace(topo.getFirst(), 1);
        while (!topo.isEmpty()) {
            Node next = topo.pollFirst();

            for (Node nei : adjList.get(next)) {
                if (dist.get(next) + 1 > dist.get(nei)) {
                    // relax
                    dist.replace(nei, dist.get(next) + 1);
                    maxRes = Math.max(maxRes, dist.get(nei));
                }
            }
        }

        System.out.println(dist);

        return maxRes;
    }

    void dfs(HashMap<Node, ArrayList<Node>> adjList, HashSet<Node> seen, LinkedList<Node> topo,
            Node parent, Node node) {

        seen.add(node);

        for (Node nei : adjList.get(node)) {
            if (nei.equals(parent)) {
                continue;
            }

            if (!seen.contains(nei)) {
                dfs(adjList, seen, topo, node, nei);
            }
        }

        //System.out.println("node: " + node + " dist: " + tmp);
        topo.addFirst(node);
    }

    static class Node {
        int width;
        int height;

        Node(int width, int height) {
            this.width = width;
            this.height = height;
        }

        boolean canFitInto(Node other) {
            return other.width > width && other.height > height;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this) {
                return true;
            }
            if (obj instanceof Node) {
                return width == ((Node) obj).width && height == ((Node) obj).height;
            }
            return false;
        }

        @Override
        public int hashCode() {
            return Objects.hash(width, height);
        }

        @Override
        public String toString() {
            return "(" + width + ", " + height + ")";
        }

    }
}
