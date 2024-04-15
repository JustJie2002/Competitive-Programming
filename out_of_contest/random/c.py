import yaml

class TrieNode:
    def __init__(self, name: str):
        self.value = name
        self.children = []

class Trie:
    def __init__(self, api):
        self.root = TrieNode(api)

    def get_all_info(self):
        def recur(node, depth):
            print("\t" * depth, node.value)
            for child in node.children:
                recur(child, depth + 1)
        recur(self.root, 0)

with open("ndir.yaml", "r") as fp:
    data = yaml.safe_load(fp)

# get, put, post

WANTED_REST_API = ["get", "put", "post"]

def recur(node, info):
    if not isinstance(info, dict):
        node.value = info
        return
    for name in info:
        node.children.append(TrieNode(name))
        recur(node.children[-1], info[name])

def helper(paths):
    for path, has_attrib in paths.items():
        api_information = []
        for api in WANTED_REST_API:
            if api in has_attrib:
                trie = Trie(api)
                recur(trie.root, has_attrib[api])
                api_information.append(trie)
        print(path)
        for api in api_information:
            api.get_all_info()
        # use path for whatever

helper(data["paths"])