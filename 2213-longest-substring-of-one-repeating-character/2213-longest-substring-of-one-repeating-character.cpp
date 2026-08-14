class SegTree
{
public:
    struct Node // [leftIndex, rightIndex]
    {
        int leftIndex, rightIndex;
        int leftSubLength, rightSubLength;
        int maxLength;
        char leftChar, rightChar;
        int leftChild, rightChild;

        int GetLength() { return rightIndex - leftIndex + 1; }
    };

    void Build(const string& s) {
        nodes.resize(s.length() * 4 + 1);
        Build(s, 1, 0, s.length()-1);
        size = s.length();
    }

    int Query(char c, int index)
    {
        Update(1, index, c);
        return nodes[1].maxLength;
    }

private:
    Node& Build(const string& s, int nodeIndex, int left, int right)
    {
        if(left == right)
        {
            return nodes[nodeIndex] = Node{left, right, 1, 1, 1, s[left], s[right], -1, -1};
        }

        int leftChildIndex = nodeIndex * 2;
        int rightChildIndex = nodeIndex * 2 + 1;
        Node& leftChild = Build(s, leftChildIndex, left, (left + right) / 2);
        Node& rightChild = Build(s, rightChildIndex, (left + right) / 2 + 1, right);

        Node& node = nodes[nodeIndex];
        node = Node{left, right,    
                    leftChild.leftSubLength, rightChild.rightSubLength,
                    max(leftChild.maxLength, rightChild.maxLength),
                    leftChild.leftChar, rightChild.rightChar,
                    leftChildIndex, rightChildIndex
                };

        if(leftChild.rightChar == rightChild.leftChar)
        {
            int substrLength = leftChild.rightSubLength + rightChild.leftSubLength;
            node.maxLength = max(node.maxLength, substrLength);

            if(leftChild.maxLength == leftChild.GetLength())
            {
                node.leftSubLength = substrLength;
            }
            if(rightChild.maxLength == rightChild.GetLength())
            {
                node.rightSubLength = substrLength;
            }
        }
        return node;
    }

    void Update(int nodeIndex, int queryIndex, char c)
    {
        if(nodeIndex <= 0 || nodeIndex >= nodes.size()) return;

        Node& node = nodes[nodeIndex];

        if(queryIndex < node.leftIndex || queryIndex > node.rightIndex) return;
        if(node.leftIndex == queryIndex && node.rightIndex == queryIndex)
        {
            node.leftChar = c;
            node.rightChar = c;
            return;
        }

        int leftChildIndex = nodeIndex * 2;
        int rightChildIndex = nodeIndex * 2 + 1;

        Update(leftChildIndex, queryIndex, c);
        Update(rightChildIndex, queryIndex, c);

        Node& leftChild = nodes[leftChildIndex];
        Node& rightChild = nodes[rightChildIndex];
    
        node = Node{node.leftIndex, node.rightIndex,    
                    leftChild.leftSubLength, rightChild.rightSubLength,
                    max(leftChild.maxLength, rightChild.maxLength),
                    leftChild.leftChar, rightChild.rightChar,
                    leftChildIndex, rightChildIndex
                };

        if(leftChild.rightChar == rightChild.leftChar)
        {
            int substrLength = leftChild.rightSubLength + rightChild.leftSubLength;
            node.maxLength = max(node.maxLength, substrLength);

            if(leftChild.maxLength == leftChild.GetLength())
            {
                node.leftSubLength = substrLength;
            }
            if(rightChild.maxLength == rightChild.GetLength())
            {
                node.rightSubLength = substrLength;
            }
        }

    }

    vector<Node> nodes;
    int size;
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res(queryIndices.size());

        SegTree segTree;
        segTree.Build(s);

        for(int i = 0; i < queryIndices.size(); ++i)
        {
            res[i] = segTree.Query(queryCharacters[i], queryIndices[i]);
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna