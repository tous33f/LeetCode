class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # forming a trie
        trie={}
        for word in strs:
            node=trie
            for char in word:
                if char not in node:
                    node[char]={}
                node=node[char]
            node['*']=True
        print(trie)
        # traversing dictionary
        ans=""
        key=list(trie.keys())[0]
        if len(list(trie.keys()))!=1 or key=='*':
            return ""
        ans=key
        node=trie[key]
        while len(node)<2 and len(node)>0 and ("*" not in list(node.keys())):
            key=list(node.keys())[0]
            ans+=key
            node=node[key]
        return ans