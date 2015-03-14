package com.aimprosoft.camed.constants;

/**
 * @author mtkachenko.
 */
public enum ActionType {
    makeMandatory(0),
    makeOptional(0),
    makeNillable(1),
    makeRepeatable(0),
    setID(1),
    setChoice(0),
    setDateMask(1),
    setStringMask(1),
    setNumberMask(1),
    setValue(1),
    restrictValues(2),
    setDefault(1),
    setNumberRange(1),
    datatype(1),
    useChoice(0),
    useElement(0),
    useTree(0),
    excludeTree(0),
    excludeElement(0),
    setLimit(1),
    setLength(1),
    makeRecursive(1),
    orderChildren(0),
    useAttribute(0),
    excludeAttribute(0),
    lookup(2),
    printMessage(1),
    applyTemplate(2),
    evaluateVariable(1);

    int numOfParams;

    ActionType(int numOfParams) {
        this.numOfParams = numOfParams;
    }

}