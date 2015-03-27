package com.aimprosoft.camed.service.evaluator;

import com.aimprosoft.camed.CamException;
import com.aimprosoft.camed.service.DocumentFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;


/**
 * @author mtkachenko.
 */
public class TemplateEvaluator {

    Document header;
    Document namespaces;
    Document structure;





//    public Boolean evaluate(CamTemplate camTemplate, DecompiledCamTemplate decompiledCamTemplate) {
//        //todo
//        return null;
//    }

    public boolean evaluate(String string1, String string2) throws CamException, ParserConfigurationException {


        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        header = builder.newDocument();
        namespaces = builder.newDocument();
        structure = builder.newDocument();



        Document documentIn = (Document) DocumentFactory.createW3Document(string1);
        Document documentOut = (Document) DocumentFactory.createW3Document(string2);


        documentIn.normalizeDocument();
        documentOut.normalizeDocument();
        header.normalizeDocument();
        namespaces.normalizeDocument();
        structure.normalizeDocument();


        Node node = documentIn.getChildNodes().item(0);



        NodeList list = node.getChildNodes();

        for(int i = 0; i <list.getLength(); i++){
            if(list.item(i).getNodeName().equals("as:Header")){
                header.importNode(list.item(i), true);
            }
            if(list.item(i).getNodeName().equals("as:Namespaces")){
                namespaces.importNode(list.item(i), true);
            }
            if(list.item(i).getNodeName().equals("as:AssemblyStructure")){
                structure.importNode(list.item(i), true);
            }
        }



        return documentIn.isEqualNode(documentOut);
    }
}
