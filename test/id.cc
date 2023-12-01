#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Player {
  string name;
  string dob;
  string nationality;
  string club;
  int height;
  int weight;
};

struct TreeNode {
  Player player;
  TreeNode* left;
  TreeNode* right;

  TreeNode(const Player& p) : player(p), left(nullptr), right(nullptr) {}
};

TreeNode* createNode(const Player& data) {
  return new TreeNode{data};
}

Player readPlayer(const string& line) {
  Player player;

  istringstream ss(line);
  getline(ss, player.name, ',');
  getline(ss, player.dob, ',');
  string token;
//  ss >> player.height;
//  ss.ignore();  // Ignore the comma
//  ss >> player.weight;
  getline(ss, token, ',');
  player.height = atoi(token.c_str());
  getline(ss, token, ',');
  player.weight = atoi(token.c_str());
  getline(ss, player.nationality, ',');
  getline(ss, player.club, ',');

  return player;
}

void insert(TreeNode*& root, const Player& player) {
  if (!root) {
    root = createNode(player);
    return;
  }

  if (player.name < root->player.name) {
    insert(root->left, player);
  } else if (player.name > root->player.name) {
    insert(root->right, player);
  }
}

// In-order traversal
void inOrderTraversal(TreeNode* root) {
  if (root != nullptr) {
    inOrderTraversal(root->left);
    cout << "\nClub now: " << root->player.club << "\t Name: " << root->player.name << " ";
    inOrderTraversal(root->right);
  }
}

TreeNode* createTree(const vector<Player>& players) {
  TreeNode* root = nullptr;
  for (const Player& player : players) {
      insert(root, player);
  }
  return root;
}

void levelOrder(TreeNode* root) {
  if (!root) return;      

  queue<TreeNode*> q;
  q.push(root);
  
  while (!q.empty()) {
    TreeNode* currNode = q.front();
    cout << currNode->player.name << " ";
    q.pop();

    if (currNode->left) {
      q.push(currNode->left);
    }
    if (currNode->right) {
      q.push(currNode->right);
    }
  }
}

vector<Player> readPlayerList(const string& file_name) {
  vector<Player> players;
  ifstream file(file_name);

  if (!file.is_open()) {
    cerr << "Cannot open file." << endl;
    return players;
  } 

  string header_line; 
  getline(file, header_line);  // Read and ignore header
  
  string line;
  while (getline(file, line)) {
    Player player = readPlayer(line);
    players.push_back(player);
  }

  return players;
}

void printPlayerList(const vector<Player>& players) {
  for (const Player& player : players) {
    cout << player.name << ' ' 
      << player.dob << ' ' 
      << player.height << "cm "
      << player.weight << "kg " 
      << player.club << ' '
      << player.nationality << endl;
  }
  cout << endl;
}

void deleteTree(TreeNode* root) {
  if (root) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;  
  }
}

//======= Enhance fucntion
vector<Player> findPlayersInClub(const vector<Player>& players, const string& clubName) {
  vector<Player> result;

  for (const Player& player : players) {
    if (player.club == clubName) {
      result.push_back(player);
    }
  }
  return result;
}


int main() {
  // Assuming players vector is already populated
  vector<Player> players = readPlayerList("Players.csv");
  
  // Build the binary tree
  TreeNode* root = createTree(players);

  // Find players in "Chelsea" club
  // string targetClub = "Chelsea";
  // vector<Player> result = findPlayersInClub(players, targetClub);
  // printPlayerList(result);


  // Display the players using in-order traversal
  cout << "In-Order Traversal of Player:\n";
  inOrderTraversal(root);

  // using level order traversal
  // cout << "\nLevel Order Traversal:\n";
  // levelOrder(root);

  // Cleanup the binary tree
  deleteTree(root);

  return 0;
}
