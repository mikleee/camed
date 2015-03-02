<as:CAM
 xmlns:as="http://www.oasis-open.org/committees/cam"
 xmlns:env="http://www.w3.org/2003/05/soap-envelope"
 xmlns:tns="https://globalordering.daimler.com/start/dms/interface/DMS_GO_DialogInterface/v1" compiled="true" CAMlevel="1" version="1.0">
  <as:Header>
    <as:Description>Generated for MoveToFront by XSD 2 CAM generator v2.04</as:Description>
    <as:Owner>To be Completed</as:Owner>
    <as:Version>0.1</as:Version>
    <as:DateTime>2014-10-30T11:39:53</as:DateTime>
  </as:Header>
  <as:Namespaces>
    <as:namespace prefix="tns">https://globalordering.daimler.com/start/dms/interface/DMS_GO_DialogInterface/v1</as:namespace>
    <as:namespace prefix="as">http://www.oasis-open.org/committees/cam</as:namespace>
    <as:namespace prefix="xml">http://www.w3.org/XML/1998/namespace</as:namespace>
    <as:namespace prefix="env">http://www.w3.org/2003/05/soap-envelope</as:namespace>
  </as:Namespaces>
  <as:AssemblyStructure>
    <as:Structure ID="MoveToFront" reference="" taxonomy="XML">
      <as:Element name="env:Envelope" makeMandatory="true">
        <as:Element name="env:Header" setValue="" makeNillable_1="xsd" makeOptional_2="true" />
        <as:Element name="env:Body" makeNillable_1="xsd" makeOptional_2="true">
          <as:Element name="tns:MoveToFront" printMessage_1="The PortalSessionId element in the MoveToFront is required and should have an AlphaNumeric value (length: [1-30]).?not(./tns:PortalSessionId[matches(.,'^[0-9a-zA-Z]{1,30}$')])" printMessage_2="The MajorVersion element in the MoveToFront is required and should be a positive number.?not(./tns:MajorVersion[matches(.,'^[1-9][0-9]*$')])" printMessage_3="The DialogSessionId element in the MoveToFront is required and should have an AlphaNumeric value (length: [1-30]).?not(./tns:DialogSessionId[matches(.,'^[0-9a-zA-Z]{1,30}$')])" makeOptional_4="true" makeNillable_5="xsd">
            <as:Element name="tns:MajorVersion" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Element name="tns:PortalSessionId" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="tns:DialogSessionId" makeNillable_1="xsd" makeOptional_2="true" />
          </as:Element>
        </as:Element>
      </as:Element>
    </as:Structure>
  </as:AssemblyStructure>
</as:CAM>