#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison object to be used to order the heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to build the frequency map
unordered_map<char, int> countFrequency(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }
    return freqMap;
}

// Class for the Huffman Tree
class HuffmanTree {
private:
    Node* root;

    // Helper function to build the Huffman Tree
    void buildTree(const unordered_map<char, int>& freqMap) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        for (const auto& pair : freqMap) {
            minHeap.push(new Node(pair.first, pair.second));
        }

        while (minHeap.size() > 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            Node* right = minHeap.top();
            minHeap.pop();

            Node* newNode = new Node('\0', left->freq + right->freq);
            newNode->left = left;
            newNode->right = right;

            minHeap.push(newNode);
        }

        root = minHeap.top();
    }

    // Helper function to generate Huffman codes
    void generateCodes(Node* node, const string& str, unordered_map<char, string>& huffmanCodes) {
        if (!node) return;

        if (!node->left && !node->right) {
            huffmanCodes[node->ch] = str;
        }

        generateCodes(node->left, str + "0", huffmanCodes);
        generateCodes(node->right, str + "1", huffmanCodes);
    }

public:
    HuffmanTree(const unordered_map<char, int>& freqMap) {
        buildTree(freqMap);
    }

    Node* getRoot() const {
        return root;
    }

    unordered_map<char, string> getHuffmanCodes() {
        unordered_map<char, string> huffmanCodes;
        generateCodes(root, "", huffmanCodes);
        return huffmanCodes;
    }
};

// Function to encode the input text using Huffman codes
string encodeText(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCodes.at(ch);
    }
    return encodedText;
}

// Function to decode the encoded text using the Huffman Tree
string decodeText(Node* root, const string& encodedText) {
    string decodedText = "";
    Node* current = root;

    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root;
        }
    }

    return decodedText;
}

int main() {
    // Frequency map as given in the problem
    unordered_map<char, int> frequencyMap = {
        {'k', 2}, {'j', 1}, {'p', 8}, {'x', 1}, {'K', 1}, {'.', 3}, 
        {'h', 7}, {'c', 4}, {'e', 17}, {'d', 7}, {'y', 2}, {'C', 1}, 
        {'o', 16}, {'n', 8}, {'a', 6}, {'w', 1}, {' ', 29}, {'g', 6}, 
        {'t', 14}, {'r', 7}, {'u', 6}, {'l', 4}, {'i', 5}, {'s', 5}, 
        {'I', 1}, {'f', 2}, {',', 1}
    };

    // Encoded string to decode
    string encodedText = "100000101000011010111001101001101101100000110100110110001010000110010100001111100110101010110111110000110011101011000011110001111101101110111111101011001100011011111010000011100011110101010110111111011011101111110001000100101011011011111001111100010000101100000111100001011110111010001001111100110101010110111000010111010011001000101111000111101001110000101011011110101001111111001110100001001110110010110110010111110110111110010101011010101101111111101101111000110010111001011001010100000001100111110100000111001100101101100101111011000101111101101110111111010101001011000111100111001011001100110111101000001110001111001100110110010111001011001010101011100101110010100101000100011010100000111";

    // Step 1: Build Huffman Tree
    HuffmanTree huffmanTree(frequencyMap);

    // Step 2: Generate Huffman Codes (if needed)
    unordered_map<char, string> huffmanCodes = huffmanTree.getHuffmanCodes();

    // Print Huffman Codes (optional)
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Step 3: Decode the encoded text
    string decodedText = decodeText(huffmanTree.getRoot(), encodedText);
    cout << "\nDecoded Text:\n" << decodedText << "\n";

    return 0;
}
