#include <fstream>
#include <iostream>
#include <unordered_map>
#include <queue>

// Calculate the depth of |node| in the |tree| and stort it into |depth|.
void CalcDepth(std::unordered_map<int, int>& tree,
               std::unordered_map<int, int>& depth,
               int node);

// Return true when two nodes in |input| are located in the same sub tree in the |tree|.
// |depth| tree is used to choose which one is more close to root.
bool HasSameRoot(std::unordered_map<int, int>& tree,
                 std::unordered_map<int, int>& depth,
                 int node_a, int inde_b);

// Get input file from argv[1], outputs into the stdout.
int main(int argc, char** argv) {
  std::unordered_map<int, int> tree; // (node, parent_node)
  std::unordered_map<int, int> depth; // (node, depth)

  std::ifstream input_file;
  input_file.open(argv[1]);

  // number of test cases.
  int test_cases;

  // Input info.
  int node_size;
  int parent_node_num;
  int node_num;

  // Query info.
  int query_num;
  int query_node_num_a;
  int query_node_num_b;

  input_file >> test_cases;
  for (int k = 0; k < test_cases; ++k) {
    // Construct tree
    depth[1] = 0; // depth of root node is zero.
    input_file >> node_size;
    input_file >> query_num;
    for (int i = 0; i < node_size - 1; ++i) {
      input_file >> parent_node_num;
      input_file >> node_num;
      if (depth.find(parent_node_num) != depth.end())
        depth[node_num] = depth[parent_node_num] + 1;
      tree[node_num] = parent_node_num;
    }

    // Solve the queries.
    for (int i = 0; i < query_num; ++i) {
      input_file >> query_node_num_a;
      input_file >> query_node_num_b;

      if (HasSameRoot(tree, depth, query_node_num_a, query_node_num_b))
        std::cout << "1" << std::endl;
      else
        std::cout << "0" << std::endl;
    } // end of queries.

    // clear hash maps.
    tree.clear();
    depth.clear();
  } // end of test case.

  input_file.close();
  return 0;
}

bool HasSameRoot(std::unordered_map<int, int>& tree,
                 std::unordered_map<int, int>& depth,
                 int input_a,
                 int input_b) {
  // Early out when two nodes are same.
  if (input_a == input_b)
    return true;

  // Early out when one of node is root node.
  if (input_a == 1 || input_b == 1)
    return true;

  if (depth.find(input_a) == depth.end())
    CalcDepth(tree, depth, input_a);
  if (depth.find(input_b) == depth.end())
    CalcDepth(tree, depth, input_b);

  int depth_of_node_a = depth[input_a];
  int depth_of_node_b = depth[input_b];

  if (depth_of_node_a == depth_of_node_b)
    return false;

  int child_node =
      (depth_of_node_a > depth_of_node_b) ? input_a : input_b;
  int target_node =
      (depth_of_node_a > depth_of_node_b) ? input_b : input_a;

  int depth_diff = std::abs(depth_of_node_a - depth_of_node_b);

  // If we can't meet |target_node| in |depth_diff| steps, we can return false.
  for (int i = 0; i < depth_diff; ++i) {
    if (tree[child_node] == target_node)
      return true;
    child_node = tree[child_node];
  }

  return false;
}

void CalcDepth(std::unordered_map<int, int>& tree,
               std::unordered_map<int, int>& depth,
               int node) {
  std::queue<int> q;
  int parent_node = tree[node];
  int node_depth = 1;

  while (true) {
    if (depth.find(parent_node) != depth.end()) {
      depth[node] = depth[parent_node] + node_depth;
      break;
    }
    q.push(parent_node);
    parent_node = tree[parent_node];
    node_depth++;
  }

  node_depth = depth[node];

  while(!q.empty()) {
    node_depth--;
    int node = q.front();
    q.pop();
    depth[node] = node_depth;
  }
}


