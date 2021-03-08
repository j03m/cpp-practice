class BinaryTreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    insertLeft(value) {
        this.left = new BinaryTreeNode(value);
        return this.left;
    }

    insertRight(value) {
        this.right = new BinaryTreeNode(value);
        return this.right;
    }
}

const head = new BinaryTreeNode(1);
head.insertLeft(2);
head.insertRight(3);
head.left.insertLeft(4);
head.left.insertRight(5);
head.right.insertLeft(6);
head.right.insertRight(7);

function dfs(){
    const nodes = [head]; //as STACK
    while(nodes.length){
        const node = nodes.pop();


        if (node.right){
            nodes.push(node.right)
        }
        if (node.left){
            nodes.push(node.left);
        }

        console.log(node.value);
    }
}

function bfs(){
    const nodes = [head]; //as QUEUE
    while(nodes.length){
        const node = nodes.pop();
        console.log(node.value);

        if (node.right){
            nodes.unshift(node.right)
        }
        if (node.left){
            nodes.unshift(node.left);
        }
        console.log(nodes)
    }
}
bfs();