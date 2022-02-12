// Question: Convert an array of email folder objects to an array of Gmail label strings.


// // Sample input:

// folders = [
//     {id: 27, parentId: 15, name: 'projects'},
//     {id: 81, parentId: 27, name: 'novel'},
//     {id: 15, parentId: 0, name: personal'}, // a parentId of 0 means root
//     {id: 35, parentId: 27, name: 'blog'},
// ]

// // Sample output:

// labels = [
//     'personal/projects',
//     'personal/projects/novel',
//     'personal',
//     'personal/projects/blog',
// ]



// Approach 1 : Reverse Mapping





#include <bits/stdc++.h>
using namespace std;

struct Folder
{
    int id;
    int parentId;
    string name;
    Folder(int _id, int _parentId, string _name)
    {
        id = _id;
        parentId = _parentId;
        name = _name;
    }
};

class Solution
{
private:
    string getParentString(int id, unordered_map<int, int> &childParentHashMap,
                           unordered_map<int, string> &idNameMap)
    {
        string parentString = "";
        while (id != 0)
        {
            parentString = idNameMap[id] + "/" + parentString;
            id = childParentHashMap[id];
        }
        parentString.pop_back();
        return parentString;
    }

public:
    vector<string> labelStrings(vector<Folder> folders)
    {
        unordered_map<int, int> childParentHashMap;
        unordered_map<int, string> idNameMap;
        for (Folder &folder : folders)
        {
            int id = folder.id;
            int parentId = folder.parentId;
            string &name = folder.name;
            childParentHashMap[id] = parentId;
            idNameMap[id] = name;
        }
        vector<string> labels;

        for (Folder &folder : folders)
        {
            int id = folder.id;
            labels.push_back(getParentString(id, childParentHashMap, idNameMap));
        }
        return labels;
    }
};

int main()
{
    Solution sol;
    vector<string> labels = sol.labelStrings({Folder(27, 15, "projects"),
                                              Folder(81, 27, "novel"),
                                              Folder(15, 0, "personal"),
                                              Folder(35, 27, "blog")});
    for (string &label : labels)
        cout << label << "\n";
}




// Approach 2: BFS




// #include <bits/stdc++.h>
// using namespace std;

// struct Folder
// {
//     int id;
//     int parentId;
//     string name;
//     Folder(int _id, int _parentId, string _name)
//     {
//         id = _id;
//         parentId = _parentId;
//         name = _name;
//     }
// };

// class Solution
// {
// public:
//     vector<string> labelStrings(vector<Folder> folders)
//     {
//         unordered_map<int, vector<int>> graph;
//         unordered_map<int, string> idNameMap;

//         for (Folder &folder : folders)
//         {
//             int id = folder.id;
//             int parentId = folder.parentId;
//             graph[parentId].push_back(id);
//             idNameMap[id] = folder.name;
//         }
//         vector<string> labels;

//         // Apply BFS, start with root node
//         queue<pair<int, string>> q;
//         q.push({0, ""});
//         while (!q.empty())
//         {
//             int sz = q.size();
//             while (sz--)
//             {
//                 pair<int, string> front = q.front();
//                 q.pop();
//                 int id = front.first;
//                 string name = front.second;
//                 if (name.length())
//                 {
//                     labels.push_back(name);
//                 }
//                 // Traverse the child nodes,
//                 for (int childId : graph[id])
//                 {
//                     string &childName = idNameMap[childId];
//                     string nextValidName = (name.length() > 0) ? (name + "/" + childName) : childName;
//                     q.push({childId, nextValidName});
//                 }
//             }
//         }
//         return labels;
//     }
// };

// int main()
// {
//     Solution sol;
//     vector<string> labels = sol.labelStrings({Folder(27, 15, "projects"),
//                                                       Folder(81, 27, "novel"),
//                                                       Folder(15, 0, "personal"),
//                                                       Folder(35, 27, "blog")});
//     for (string &label : labels)
//         cout << label << "\n";
// }