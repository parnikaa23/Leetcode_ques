private void ConstructGraph(TreeNode node, Dictionary<int, List<int>> graph)
{
    List<int> currList = graph[node.val];
    if(node.left != null)
    {
        currList.Add(node.left.val);
        graph[node.left.val] = new List<int>() { node.val };
        ConstructGraph(node.left, graph);
    }
    if(node.right != null)
    {
        currList.Add(node.right.val);
        graph[node.right.val] = new List<int>() { node.val };
        ConstructGraph(node.right, graph);
    }
}

private void ConstructGraph(TreeNode node, Dictionary<int, List<int>> graph)
{
     if(node.left != null)
     {
         graph[node.val].Add(node.left.val);
         graph[node.left.val] = new List<int>() { node.val };
         ConstructGraph(node.left, graph);
     }
     if(node.right != null)
     {
         graph[node.val].Add(node.right.val);
         graph[node.right.val] = new List<int>() { node.val };
         ConstructGraph(node.right, graph);
     }
}