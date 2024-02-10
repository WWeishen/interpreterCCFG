import { integer } from "vscode-languageclient";

export abstract class Node {
    static uidCounter: integer = 0;
    uid: integer;
    value:any;
    constructor(value: any) {
        this.uid = Node.uidCounter++;
        this.value = value;
    }

    getType(): string {
        return this.constructor.name;
    }
}

export class Edge {
    from: Node;
    to: Node;
    label?: string;

    constructor(from: Node, to: Node, label?: string) {
        this.from = from;
        this.to = to;
        this.label = label;
    }
}

export class Graph {
    nodes: Node[];
    edges: Edge[];
    ;

    constructor() {
        this.nodes = [];
        this.edges = [];
    }

    addNode(node: Node): Node {
        let res = this.nodes.find(n => n === node);
        if (res == undefined) {
            this.nodes.push(node);
        }
        return node;
    }

    addEdge(from: Node, to: Node, label:string=""): void {
        let res = this.edges.find(e => e.from === from && e.to === to);
        if (res == undefined) {
            const edge = new Edge(from, to);
            this.edges.push(edge);
        }
    }

  


    toDot(): string {
        let dot = 'digraph G {\n';
        for (let node of this.nodes) {
            let shape:string = this.getNodeShape(node); 
            let label:string = this.getNodeLabel(node);
            dot += `  "${node.uid}" [label="${label}" shape="${shape}"];\n`;
        }
        for (let edge of this.edges) {
            dot += `  "${edge.from.uid}" -> "${edge.to.uid}" [label="${(edge.label != undefined)?edge.label:""}"];\n`;
        }
        dot += '}';
        return dot;
    }

    getNodeLabel(node: Node): string {
        //return node.value;
        switch(node.getType()){
            case "Step":
                return node.uid.toString();
            case "Choice":
                return node.uid.toString();
            case "OrJoin":
                return "or";
            case "AndJoin":
                return "&&";
            case "Fork":
                return "||";
            default:
                return "???"+node.uid.toString();
        }
    }

    getNodeShape(node: Node): string {
        switch(node.getType()){
            case "Step":
                return "ellipse";
            case "Choice":
                return "diamond";
            case "OrJoin":
                return "invtriangle";
            case "AndJoin":
                return "invtriangle";
            case "Fork":
                return "triangle";
            default:
                return "box";
        }
    }

}

export class Step extends Node {
    constructor(value: any) {
        super(value);
    }
}

export class Choice extends Node {
    constructor(value: any) {
        super(value);
    }
}

export class Join extends Node {
    constructor(value: any) {
        super(value);
    }
}

export class Fork extends Node {
    constructor(value: any) {
        super(value);
    }
}

export class OrJoin extends Join {
    constructor(value: any) {
        super(value);
    }
}

export class AndJoin extends Join {
    constructor(value: any) {
        super(value);
    }
}



// // Create a new graph
// let graph = new Graph();

// // Add nodes to the graph
// let stepNode1 = new Step("Step Node");
// let stepNode2 = new Step("Step Node");
// let stepNode3 = new Step("Step Node");
// let stepNode4 = new Step("Step Node");
// let stepNode5 = new Step("Step Node");
// let stepNode6 = new Step("Step Node");
// let stepNode7 = new Step("Step Node");

// let choiceNode = new Choice("Choice Node");
// let orJoinNode = new OrJoin("Or Join Node");
// let andJoinNode = new AndJoin("And Join Node");

// let forkNode = new Fork("Fork Node");

// graph.addNode(stepNode1);
// graph.addNode(stepNode2);
// graph.addNode(stepNode3);
// graph.addNode(stepNode4);
// graph.addNode(stepNode5);
// graph.addNode(stepNode6);
// graph.addNode(stepNode7);
// graph.addNode(choiceNode);
// graph.addNode(orJoinNode);
// graph.addNode(andJoinNode);
// graph.addNode(forkNode);

// // Add edges to the graph
// graph.addEdge(stepNode1, choiceNode);
// graph.addEdge(choiceNode, stepNode2);
// graph.addEdge(choiceNode, stepNode3);
// graph.addEdge(stepNode3, orJoinNode);
// graph.addEdge(stepNode2, orJoinNode);
// graph.addEdge(orJoinNode, stepNode4);
// graph.addEdge(stepNode4, forkNode);
// graph.addEdge(forkNode, stepNode5);
// graph.addEdge(forkNode, stepNode6);
// graph.addEdge(stepNode5, andJoinNode);
// graph.addEdge(stepNode6, andJoinNode);
// graph.addEdge(andJoinNode, stepNode7);

// // Export the graph to the Graphviz DOT format
// let dot = graph.toDot();
// console.log(dot);