#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Node structure for Huffman Tree
struct Node {
    int pixel_value;
    int frequency;
    Node* left;
    Node* right;

    Node(int value, int freq) : pixel_value(value), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Traverse the Huffman Tree and store codes in a map
void storeCodes(Node* root, string str, unordered_map<int, string>& huffmanCodes) {
    if (!root) return;

    if (root->pixel_value != -1) {
        huffmanCodes[root->pixel_value] = str;
    }

    storeCodes(root->left, str + "0", huffmanCodes);
    storeCodes(root->right, str + "1", huffmanCodes);
}

// Build the Huffman Tree and generate codes
void buildHuffmanTree(vector<int>& frequencies, unordered_map<int, string>& huffmanCodes) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (int i = 0; i < 256; ++i) {
        if (frequencies[i] > 0) {
            minHeap.push(new Node(i, frequencies[i]));
        }
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* top = new Node(-1, left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    storeCodes(minHeap.top(), "", huffmanCodes);
}

// Compress the image using Huffman codes
string compressImage(const Mat& img, unordered_map<int, string>& huffmanCodes) {
    string compressedData = "";
    for (int row = 0; row < img.rows; ++row) {
        for (int col = 0; col < img.cols; ++col) {
            int pixel_value = img.at<uchar>(row, col);
            compressedData += huffmanCodes[pixel_value];
        }
    }
    return compressedData;
}

int main() {
    // Read the image file
    Mat image = imread("image.jpg", IMREAD_GRAYSCALE);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Calculate frequency of each pixel value
    vector<int> frequencies(256, 0);
    for (int row = 0; row < image.rows; ++row) {
        for (int col = 0; col < image.cols; ++col) {
            int pixel_value = image.at<uchar>(row, col);
            frequencies[pixel_value]++;
        }
    }

    // Build Huffman Tree and generate codes
    unordered_map<int, string> huffmanCodes;
    buildHuffmanTree(frequencies, huffmanCodes);

    // Compress the image
    string compressedData = compressImage(image, huffmanCodes);

    // Output compressed data size
    cout << "Original size: " << image.rows * image.cols * 8 << " bits" << endl;
    cout << "Compressed size: " << compressedData.size() << " bits" << endl;

    // (Optional) Save the compressed data and Huffman codes for decompression later

    return 0;
}
