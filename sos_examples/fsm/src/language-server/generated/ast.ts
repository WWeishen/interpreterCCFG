/******************************************************************************
 * This file was generated by langium-cli 1.0.0.
 * DO NOT EDIT MANUALLY!
 ******************************************************************************/

/* eslint-disable */
import { AstNode, AbstractAstReflection, Reference, ReferenceInfo, TypeMetaData } from 'langium';

export interface Event extends AstNode {
    readonly $container: FSMModel;
    readonly $type: 'Event';
    name: string
}

export const Event = 'Event';

export function isEvent(item: unknown): item is Event {
    return reflection.isInstance(item, Event);
}

export interface FSM extends AstNode {
    readonly $container: FSMModel;
    readonly $type: 'FSM';
    name: string
    states: Array<State>
    transitions: Array<Transition>
}

export const FSM = 'FSM';

export function isFSM(item: unknown): item is FSM {
    return reflection.isInstance(item, FSM);
}

export interface FSMModel extends AstNode {
    readonly $type: 'FSMModel';
    events: Array<Event>
    fsms: Array<FSM>
}

export const FSMModel = 'FSMModel';

export function isFSMModel(item: unknown): item is FSMModel {
    return reflection.isInstance(item, FSMModel);
}

export interface State extends AstNode {
    readonly $container: FSM;
    readonly $type: 'State';
    inTransitions: Array<Reference<Transition>>
    isInitial: boolean
    name: string
    outTransitions: Array<Reference<Transition>>
}

export const State = 'State';

export function isState(item: unknown): item is State {
    return reflection.isInstance(item, State);
}

export interface Transition extends AstNode {
    readonly $container: FSM;
    readonly $type: 'Transition';
    guardEvent?: Reference<Event>
    name: string
    sentEvent: Reference<Event>
    source: Reference<State>
    target: Reference<State>
    time?: number
}

export const Transition = 'Transition';

export function isTransition(item: unknown): item is Transition {
    return reflection.isInstance(item, Transition);
}

export interface FiniteStateMachineAstType {
    Event: Event
    FSM: FSM
    FSMModel: FSMModel
    State: State
    Transition: Transition
}

export class FiniteStateMachineAstReflection extends AbstractAstReflection {

    getAllTypes(): string[] {
        return ['Event', 'FSM', 'FSMModel', 'State', 'Transition'];
    }

    protected override computeIsSubtype(subtype: string, supertype: string): boolean {
        switch (subtype) {
            default: {
                return false;
            }
        }
    }

    getReferenceType(refInfo: ReferenceInfo): string {
        const referenceId = `${refInfo.container.$type}:${refInfo.property}`;
        switch (referenceId) {
            case 'State:inTransitions':
            case 'State:outTransitions': {
                return Transition;
            }
            case 'Transition:guardEvent':
            case 'Transition:sentEvent': {
                return Event;
            }
            case 'Transition:source':
            case 'Transition:target': {
                return State;
            }
            default: {
                throw new Error(`${referenceId} is not a valid reference id.`);
            }
        }
    }

    getTypeMetaData(type: string): TypeMetaData {
        switch (type) {
            case 'FSM': {
                return {
                    name: 'FSM',
                    mandatory: [
                        { name: 'states', type: 'array' },
                        { name: 'transitions', type: 'array' }
                    ]
                };
            }
            case 'FSMModel': {
                return {
                    name: 'FSMModel',
                    mandatory: [
                        { name: 'events', type: 'array' },
                        { name: 'fsms', type: 'array' }
                    ]
                };
            }
            case 'State': {
                return {
                    name: 'State',
                    mandatory: [
                        { name: 'inTransitions', type: 'array' },
                        { name: 'isInitial', type: 'boolean' },
                        { name: 'outTransitions', type: 'array' }
                    ]
                };
            }
            default: {
                return {
                    name: type,
                    mandatory: []
                };
            }
        }
    }
}

export const reflection = new FiniteStateMachineAstReflection();
