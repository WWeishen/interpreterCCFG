
import { AstNode, Reference, isReference } from "langium";
import { AndJoin, Fork, CCFG, Node, OrJoin, Step } from "../../ccfg/ccfglib";
import { FSMModel,FSM,Event,State,Transition } from "../../language-server/generated/ast";

export interface SimpleLVisitor {
    visit(node: AstNode| Reference<AstNode>): [Node,Node];
    

     visitFSMModel(node: FSMModel): [Node,Node];
     visitFSM(node: FSM): [Node,Node];
     visitEvent(node: Event): [Node,Node];
     visitState(node: State): [Node,Node];
     visitTransition(node: Transition): [Node,Node];
}


    function getASTNodeUID(node: AstNode | AstNode[] | Reference<AstNode> | Reference<AstNode>[] | undefined ): any {
        if(node === undefined){
            throw new Error("not possible to get the UID of an undefined AstNode")
        }
        if(Array.isArray(node)){
           
            if(node.some(n => isReference(n))){
                let unrefed = node.map(r => isReference(r)?(r as Reference<AstNode>).ref:r)
                let noUndef : AstNode[]  = []
                for (let e of unrefed) {
                    if(e !== undefined){
                        noUndef.push(e)
                    }
                }
                return getASTNodeUID(noUndef)
            }
            var rs = node.map(n => (n as AstNode).$cstNode?.range)
            return "array"+rs.map(r => r?.start.line+"_"+r?.start.character+"_"+r?.end.line+"_"+r?.end.character).join("_");
        }
        
        if(isReference(node)){
            return getASTNodeUID(node.ref)
        }

        var r = node.$cstNode?.range
        return node.$type+r?.start.line+"_"+r?.start.character+"_"+r?.end.line+"_"+r?.end.character;
    }


export class CCFGVisitor implements SimpleLVisitor {
    ccfg: CCFG = new CCFG();

  
    

    visit(node: AstNode | Reference<AstNode>): [Node,Node] {
        if(isReference(node)){
            if(node.ref === undefined){
                throw new Error("not possible to visit an undefined AstNode")
            }
            node = node.ref
        }
        if(node.$type == "FSMModel"){
            return this.visitFSMModel(node as FSMModel);
        }
        if(node.$type == "FSM"){
            return this.visitFSM(node as FSM);
        }
        if(node.$type == "Event"){
            return this.visitEvent(node as Event);
        }
        if(node.$type == "State"){
            return this.visitState(node as State);
        }
        if(node.$type == "Transition"){
            return this.visitTransition(node as Transition);
        }
        throw new Error("Not implemented: " + node.$type);
    }
    
    visitFSMModel(node: FSMModel): [Node,Node] {
        let startsFSMModelNode: Node = new Step("starts"+getASTNodeUID(node),[])
        if(startsFSMModelNode.functionsDefs.length>0){
            startsFSMModelNode.returnType = "void"
        }
        startsFSMModelNode.functionsNames = [`init${startsFSMModelNode.uid}FSMModel`]
        this.ccfg.addNode(startsFSMModelNode)
        let terminatesFSMModelNode: Node = new Step("terminates"+getASTNodeUID(node))
        this.ccfg.addNode(terminatesFSMModelNode)
        // rule FSMstart
   //premise: starts:event
   //conclusion: fsms:FSM[],fsm:unknown,starts:event
// rule FSMend
   //premise: fsms:FSM[],terminates:event
   //conclusion: terminates:event

        let previousNode =undefined
        
    {
        let startsnodeFSMstart = this.retrieveNode("starts",node) //retrieve 1
        previousNode = startsnodeFSMstart
    }
    
        let FSMstartForkNode: Node = new Fork("FSMstartForkNode")
        this.ccfg.addNode(FSMstartForkNode)
        {let e = this.ccfg.addEdge(previousNode,FSMstartForkNode)
        e.guards = [...e.guards, ...[]] //CC
        }

        let FSMstartFakeNode: Node = new AndJoin("FSMstartFakeNode")    
        this.ccfg.addNode(FSMstartFakeNode)    
        for (var child of node.fsms) {
            let [childStartsNode,childTerminatesNode] = this.getOrVisitNode(child)
            this.ccfg.addEdge(FSMstartForkNode,childStartsNode)
            this.ccfg.addEdge(childTerminatesNode,FSMstartFakeNode)
        }

        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}FSMstart`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
    let FSMendLastOfNode: Node = new AndJoin("lastOfNode"+getASTNodeUID(node.fsms))
    this.ccfg.replaceNode(FSMstartFakeNode,FSMendLastOfNode)                    
                
    {
        let lastOfNodenode_fsmsFSMend = this.retrieveNode("lastOfNode",node.fsms) //retrieve 1
        previousNode = lastOfNodenode_fsmsFSMend
    }
    
        {let e = this.ccfg.addEdge(previousNode,terminatesFSMModelNode)
        e.guards = [...e.guards, ...[]] //EE
        }
        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}FSMend`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
        return [startsFSMModelNode,terminatesFSMModelNode]
    }

    visitFSM(node: FSM): [Node,Node] {
        let startsFSMNode: Node = new Step("starts"+getASTNodeUID(node),[`sigma["${getASTNodeUID(node)}currentState"] = new unknown();`])
        if(startsFSMNode.functionsDefs.length>0){
            startsFSMNode.returnType = "void"
        }
        startsFSMNode.functionsNames = [`init${startsFSMNode.uid}FSM`]
        this.ccfg.addNode(startsFSMNode)
        let terminatesFSMNode: Node = new Step("terminates"+getASTNodeUID(node))
        this.ccfg.addNode(terminatesFSMNode)
        // rule fsmInit
   //premise: starts:event
   //conclusion: initialState:[State:ID],starts:event

        let previousNode =undefined
        
    {
        let startsnodefsmInit = this.retrieveNode("starts",node) //retrieve 1
        previousNode = startsnodefsmInit
    }
    
    {let fsmInitStateModificationNode: Node = new Step("fsmInitStateModificationNode")
    this.ccfg.addNode(fsmInitStateModificationNode)
    let e = this.ccfg.addEdge(previousNode,fsmInitStateModificationNode)
    e.guards = [...e.guards, ...[]]
    previousNode = fsmInitStateModificationNode
    }
    previousNode.functionsNames = [...previousNode.functionsNames, ...[`${previousNode.uid}fsmInit`]] 
    previousNode.functionsDefs =[...previousNode.functionsDefs, ...[`unknown ${getASTNodeUID(node)}549 = ${node.initialState}; //undefined`,`//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);
                (*((unknown*)sigma["${getASTNodeUID(node)}currentState"])) = ${getASTNodeUID(node)}549;`]] //AA
    
        let initialStateStartsNodefsmInit = this.retrieveNode("starts",node.initialState)
        
            {
            let e = this.ccfg.addEdge(previousNode,initialStateStartsNodefsmInit)
            e.guards = [...e.guards, ...[]] //FF
            }
            
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}fsmInit`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
        return [startsFSMNode,terminatesFSMNode]
    }

    visitEvent(node: Event): [Node,Node] {
        let startsEventNode: Node = new Step("starts"+getASTNodeUID(node),[])
        if(startsEventNode.functionsDefs.length>0){
            startsEventNode.returnType = "void"
        }
        startsEventNode.functionsNames = [`init${startsEventNode.uid}Event`]
        this.ccfg.addNode(startsEventNode)
        let terminatesEventNode: Node = new Step("terminates"+getASTNodeUID(node))
        this.ccfg.addNode(terminatesEventNode)
        // rule fugaceEvent
   //premise: starts:event
   //conclusion: terminates:event

        let previousNode =undefined
        
    {
        let startsnodefugaceEvent = this.retrieveNode("starts",node) //retrieve 1
        previousNode = startsnodefugaceEvent
    }
    
        {let e = this.ccfg.addEdge(previousNode,terminatesEventNode)
        e.guards = [...e.guards, ...[]] //EE
        }
        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}fugaceEvent`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
        return [startsEventNode,terminatesEventNode]
    }

    visitState(node: State): [Node,Node] {
        let startsStateNode: Node = new Step("starts"+getASTNodeUID(node),[])
        if(startsStateNode.functionsDefs.length>0){
            startsStateNode.returnType = "void"
        }
        startsStateNode.functionsNames = [`init${startsStateNode.uid}State`]
        this.ccfg.addNode(startsStateNode)
        let terminatesStateNode: Node = new Step("terminates"+getASTNodeUID(node))
        this.ccfg.addNode(terminatesStateNode)
        // rule stateInit
   //premise: starts:event
   //conclusion: outTransitions:[Transition:ID][],transition:unknown,starts:event
// rule stateEnd
   //premise: outTransitions:[Transition:ID][],terminates:event
   //conclusion: terminates:event

        let previousNode =undefined
        
    {
        let startsnodestateInit = this.retrieveNode("starts",node) //retrieve 1
        previousNode = startsnodestateInit
    }
    
        let stateInitForkNode: Node = new Fork("stateInitForkNode")
        this.ccfg.addNode(stateInitForkNode)
        {let e = this.ccfg.addEdge(previousNode,stateInitForkNode)
        e.guards = [...e.guards, ...[]] //CC
        }

        let stateInitFakeNode: Node = new AndJoin("stateInitFakeNode")    
        this.ccfg.addNode(stateInitFakeNode)    
        for (var child of node.outTransitions) {
            let [childStartsNode,childTerminatesNode] = this.getOrVisitNode(child)
            this.ccfg.addEdge(stateInitForkNode,childStartsNode)
            this.ccfg.addEdge(childTerminatesNode,stateInitFakeNode)
        }

        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}stateInit`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
    let stateEndFirstOfNode: Node = new OrJoin("firstOfNode"+getASTNodeUID(node.outTransitions))
    this.ccfg.replaceNode(stateInitFakeNode,stateEndFirstOfNode)
                
    {
        let firstOfNodenode_outTransitionsstateEnd = this.retrieveNode("firstOfNode",node.outTransitions) //retrieve 1
        previousNode = firstOfNodenode_outTransitionsstateEnd
    }
    
        {let e = this.ccfg.addEdge(previousNode,terminatesStateNode)
        e.guards = [...e.guards, ...[]] //EE
        }
        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}stateEnd`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
        return [startsStateNode,terminatesStateNode]
    }

    visitTransition(node: Transition): [Node,Node] {
        let startsTransitionNode: Node = new Step("starts"+getASTNodeUID(node),[`sigma["${getASTNodeUID(node)}isSensitive"] = new bool(false);`])
        if(startsTransitionNode.functionsDefs.length>0){
            startsTransitionNode.returnType = "void"
        }
        startsTransitionNode.functionsNames = [`init${startsTransitionNode.uid}Transition`]
        this.ccfg.addNode(startsTransitionNode)
        let terminatesTransitionNode: Node = new Step("terminates"+getASTNodeUID(node))
        this.ccfg.addNode(terminatesTransitionNode)
        // rule transitionInit
   //premise: starts:event
// rule fire
   //premise: guardEvent:[Event:ID],terminates:event
   //conclusion: sentEvent:[Event:ID],starts:event
// rule transitionEnd
   //premise: sentEvent:[Event:ID],terminates:event
   //conclusion: terminates:event
   //conclusion: terminates:event,target:[State:ID],starts:event

        let previousNode =undefined
        
    {
        let startsnodetransitionInit = this.retrieveNode("starts",node) //retrieve 1
        previousNode = startsnodetransitionInit
    }
    
        // conclusion with no event emission
                
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}transitionInit`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
    {
        let terminatesnode_guardEventfire = this.retrieveNode("terminates",node.guardEvent) //retrieve 1
        previousNode = terminatesnode_guardEventfire
    }
    
        let sentEventStartsNodefire = this.retrieveNode("starts",node.sentEvent)
        
            {
            let e = this.ccfg.addEdge(previousNode,sentEventStartsNodefire)
            e.guards = [...e.guards, ...[]] //FF
            }
            
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}fire`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
    {
        let terminatesnode_sentEventtransitionEnd = this.retrieveNode("terminates",node.sentEvent) //retrieve 1
        previousNode = terminatesnode_sentEventtransitionEnd
    }
    
        this.ccfg.addEdge(previousNode,terminatesTransitionNode)
        previousNode = terminatesTransitionNode
        
        let [targetStartNode,targetTerminatesNode] = this.getOrVisitNode(node.target)
        this.ccfg.addEdge(previousNode,targetStartNode)
        previousNode = targetTerminatesNode
        
        previousNode.returnType = "void"
        previousNode.functionsNames = [`${previousNode.uid}transitionEnd`] //overwrite existing name
        previousNode.functionsDefs =[...previousNode.functionsDefs, ...[]] //GG
    
        return [startsTransitionNode,terminatesTransitionNode]
    }

    getOrVisitNode(node:AstNode | Reference<AstNode> |undefined): [Node,Node]{
        if(node === undefined){
            throw new Error("not possible to get or visit an undefined AstNode")
        }     
        if(isReference(node)){
            if(node.ref === undefined){
                throw new Error("not possible to visit an undefined AstNode")
            }
            node = node.ref
        }

        let startsNode = this.ccfg.getNodeFromName("starts"+getASTNodeUID(node))
        if(startsNode !== undefined){
            let terminatesNode = this.ccfg.getNodeFromName("terminates"+getASTNodeUID(node))
            if(terminatesNode === undefined){
                throw new Error("impossible to be there")
            }
            return [startsNode,terminatesNode]
        }
        let [starts,terminates] = this.visit(node)
        return [starts,terminates]
    }

    retrieveNode(prefix: string, node: AstNode | AstNode[] | Reference<AstNode> | Reference<AstNode>[] | undefined): Node {
        if(node === undefined){
            throw new Error("not possible to retrieve a node from an undefined AstNode")
        }
        if(Array.isArray(node) || (prefix != "starts" && prefix != "terminates")){
            let n = this.ccfg.getNodeFromName(prefix+getASTNodeUID(node))
            if(n === undefined){
                throw new Error("impossible to retrieve "+prefix+getASTNodeUID(node)+ "from the ccfg")
            }
            return n
        }
        if(prefix == "starts"){
            return this.getOrVisitNode(node)[0]
        }
        if(prefix == "terminates"){
            return this.getOrVisitNode(node)[1]
        }       
        throw new Error("not possible to retrieve the node given as parameter: "+prefix+getASTNodeUID(node))
    }
    
}
