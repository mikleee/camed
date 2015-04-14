<as:CAM
 xmlns:as="http://www.oasis-open.org/committees/cam"
 xmlns:camed="http://jcam.org.uk/editor"
 xmlns:oagis="http://www.openapplications.org/oagis/9"
 xmlns:star="http://www.starstandard.org/STAR/5"
 xmlns:xsd="http://www.w3.org/2001/XMLSchema" compiled="true" CAMlevel="1" version="1.0">
  <as:Header>
    <as:Description>Generated for GetCustomerInformation  by XSD 2 CAM generator v2.04 then edited by Tony Slosar</as:Description>
    <as:Owner>Motive Retail LLC</as:Owner>
    <as:Version>0.3</as:Version>
    <as:DateTime>2014-02-21T16:00:09</as:DateTime>
  </as:Header>
  <as:Namespaces>
    <as:namespace prefix="xsd">http://www.w3.org/2001/XMLSchema</as:namespace>
    <as:namespace prefix="star">http://www.starstandard.org/STAR/5</as:namespace>
    <as:namespace prefix="as">http://www.oasis-open.org/committees/cam</as:namespace>
    <as:namespace prefix="oagis">http://www.openapplications.org/oagis/9</as:namespace>
    <as:namespace prefix="xml">http://www.w3.org/XML/1998/namespace</as:namespace>
    <as:namespace prefix="camed">http://jcam.org.uk/editor</as:namespace>
  </as:Namespaces>
  <as:AssemblyStructure>
    <as:Structure ID="GetCustomerInformation" reference="" taxonomy="XML">
      <as:Element name="star:GetCustomerInformation" printMessage_1="The releaseID attribute must contain the value '5.7.3' or '5.8.3'.?not(./@releaseID[matches(.,'^5.7.3$')] or ./@releaseID[matches(.,'^5.8.3$')])">
        <as:Attribute name="releaseID" makeMandatory="true" />
        <as:Attribute name="versionID" makeOptional_1="true" makeNillable_2="xsd" />
        <as:Attribute name="systemEnvironmentCode" makeOptional_1="true" makeNillable_2="xsd" />
        <as:Attribute name="languageCode" makeOptional_1="true" makeNillable_2="xsd" />
        <as:Element name="star:ApplicationArea" printMessage_1="The BODID element is required and must contain a GUID.?not(./star:BODID) or not(string-length(./star:BODID) = 36 or string-length(./star:BODID) = 45) or              ./star:BODID[matches(.,'[ *,.;=+_?#$%@\^\\/!&gt;|}{()]')] or contains(./star:BODID,'[') or contains(./star:BODID,']')" printMessage_2="The CreationDateTime element must contain a date/time value in the format YYYY-MM-DDTHH:MM:SS.fffZ.?not(./star:CreationDateTime[matches(.,'^20\d\d-[0-1]\d-[0-3]\dT[0-2]\d:[0-5]\d:[0-5]\d.\d\d\dZ$')])">
          <as:Element name="star:Sender" printMessage_1="The DealerCountryCode element is required in the Sender component with the value 'US'.?not(./star:DealerCountryCode) or not(./star:DealerCountryCode[matches(.,'US')])" printMessage_2="The SenderNameCode element must contain a valid STAR Short Code.?not(./star:SenderNameCode[matches(.,'^[A-Z0-9]{2}$')])" printMessage_3="The LanguageCode element is required in the Sender component with the value 'en-US'.?not(./star:LanguageCode) or not(./star:LanguageCode[matches(.,'en-US')])" printMessage_4="The CreatorNameCode element in the Sender component must have an alpha-numeric-special value no longer than 32 characters in length.?string-length(./star:CreatorNameCode) &gt; 32">
            <as:Element name="star:LogicalID" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:ComponentID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:TaskID" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:ReferenceID" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:ConfirmationCode" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Element name="star:AuthorizationID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:CreatorNameCode" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:SenderNameCode" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:URI" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="star:DealerNumberID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:StoreNumber" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:AreaNumber" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:DealerCountryCode" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Element name="star:LanguageCode" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="star:DeliverPendingMailIndicator" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Element name="star:Password" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:SystemVersion" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Element name="star:PartyID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:LocationID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:ServiceID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:NounCountNumeric" makeOptional_1="true" makeNillable_2="xsd" />
          </as:Element>
          <as:Element name="star:CreationDateTime" makeNillable_1="xsd" makeOptional_2="true" />
          <as:Element name="oagis:Signature" makeOptional_1="true" makeNillable_2="xsd">
            <as:Attribute name="qualifyingAgencyId" makeOptional_1="true" makeNillable_2="xsd" />
          </as:Element>
          <as:Element name="star:BODID" makeOptional_1="true" makeNillable_2="xsd">
            <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
          </as:Element>
          <as:Element name="star:Destination" printMessage_1="The ServiceMessageID element is required in the Destination component with the value 'Customer'.?not(./star:ServiceMessageID) or not(./star:ServiceMessageID[matches(.,'^Customer$')])" printMessage_2="The DestinationSoftwareCode element is required in the Destination component with the value 'AutosoftFlexConnect'.?not(./star:DestinationSoftwareCode) or not(./star:DestinationSoftwareCode[matches(.,'^AutosoftFlexConnect$')])" printMessage_3="The DestinationNameCode element is required in the Destination component with the value 'AS'.?not(./star:DestinationNameCode) or not(./star:DestinationNameCode[matches(.,'^AS$')])" printMessage_4="The DealerTargetCountry element is required in the Destination component with the value 'US'.?not(./star:DealerTargetCountry) or not(./star:DealerTargetCountry[matches(.,'US')])" printMessage_5="The DealerNumberID element is required in the Destination component and must contain an alpha-numeric value 6 characters in length.?not(./star:DealerNumberID) or             not(string-length(./star:DealerNumberID) = 6) or             ./star:DealerNumberID[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./star:DealerNumberID,'[') or contains(./star:DealerNumberID,']')">
            <as:Element name="star:DestinationNameCode" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:DestinationURI" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="star:DestinationSoftwareCode" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:DestinationSoftware" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:DealerNumberID" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:StoreNumber" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:AreaNumber" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
            </as:Element>
            <as:Element name="star:DealerTargetCountry" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="star:PartyReceiverID" makeOptional_1="true" makeNillable_2="xsd">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:LocationReceiverID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
            <as:Element name="star:ServiceMessageID" makeNillable_1="xsd" makeOptional_2="true">
              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
          </as:Element>
        </as:Element>
        <as:Element name="star:GetCustomerInformationDataArea" makeMandatory="true">
          <as:Element name="star:Get" printMessage_1="If the expressionLanguage attribute value is 'OrganizationName' values of 'CustomerFirstName' or 'CustomerLastName' can not be sent.?./oagis:Expression/@expressionLanguage = 'OrganizationName' and (./oagis:Expression/@expressionLanguage = 'CustomerFirstName' or ./oagis:Expression/@expressionLanguage = 'CustomerLastName')" printMessage_2="A particular expressionLanguage attribute value can occur only once.?count(./oagis:Expression) &gt; 1 and              (count(./oagis:Expression[@expressionLanguage = 'CustomerID']) &gt; 1 or              count(./oagis:Expression[@expressionLanguage = 'CustomerFirstName']) &gt; 1 or              count(./oagis:Expression[@expressionLanguage = 'CustomerLastName']) &gt; 1 or              count(./oagis:Expression[@expressionLanguage = 'OrganizationName']) &gt; 1 or             count(./oagis:Expression[@expressionLanguage = 'PhoneNumber']) &gt; 1 or             count(./oagis:Expression[@expressionLanguage = 'Email']) &gt; 1 or             count(./oagis:Expression[@expressionLanguage = 'Zip']) &gt; 1)" printMessage_3="No more than 7 occurences of the Expression element can be present.?count(./oagis:Expression) &gt; 7">
            <as:Attribute name="uniqueIndicator" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Attribute name="maxItems" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Attribute name="recordSetSaveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
            <as:Attribute name="recordSetStartNumber" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Attribute name="recordSetReferenceId" makeNillable_1="xsd" makeOptional_2="true" />
            <as:Element name="oagis:Expression" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:Get/oagis:Expression" printMessage_4="When the expressionLanguage attribute is 'PhoneNumber' the Expression element must contain a numeric value exactly 10 characters in length.?./@expressionLanguage = 'PhoneNumber' and (not(string-length(.) = 10) or .[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(.,'[') or contains(.,']') or .[matches(.,'[A-Za-z]')])" printMessage_5="When the expressionLanguage attribute is 'CustomerLastName' the Expression element must contain an alpha-numeric-special value no more than 75 characters in length.?./@expressionLanguage = 'CustomerLastName' and string-length(.) &gt; 75" printMessage_6="When the expressionLanguage attribute is 'Email' the Expression element must contain an alpha-numeric-special value no more than 100 characters in length.?./@expressionLanguage = 'Email' and string-length(.) &gt; 100" printMessage_7="When the expressionLanguage attribute is 'CustomerID' the Expression element must contain an alpha-numeric value between 9 and 15 characters in length.?./@expressionLanguage = 'CustomerID' and (string-length(.) &lt; 9 or string-length(.) &gt; 15 or .[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(.,'[') or contains(.,']'))" printMessage_8="When the expressionLanguage attribute is 'OrganizationName' the Expression element must contain an alpha-numeric-special value no more than 100 characters in length.?./@expressionLanguage = 'OrganizationName' and string-length(.) &gt; 100" printMessage_9="If a value is sent in the Expression element a value must also be sent in its expressionLanguage attribute.?not(./@expressionLanguage) or not(string-length(./@expressionLanguage) &gt; 0) or not(string-length(.) &gt; 0)" printMessage_10="The expressionLanguage attribute on the Expression element must contain one of the enumerated values 'CustomerID' 'CustomerFirstName' 'CustomerLastName' 'OrganizationName' 'PhoneNumber' 'Email' 'Zip'.?not(./@expressionLanguage = 'CustomerID' or ./@expressionLanguage = 'CustomerFirstName' or ./@expressionLanguage = 'CustomerLastName' or ./@expressionLanguage = 'OrganizationName' or ./@expressionLanguage = 'PhoneNumber' or ./@expressionLanguage = 'Email' or ./@expressionLanguage = 'Zip')" printMessage_11="When the expressionLanguage attribute is 'CustomerFirstName' the Expression element must contain an alpha-numeric-special value no more than 75 characters in length.?./@expressionLanguage = 'CustomerFirstName' and string-length(.) &gt; 75" printMessage_12="When the expressionLanguage attribute is 'Zip' the Expression element must contain a numeric value either 5 or 9 characters in length.?./@expressionLanguage = 'Zip' and (not(string-length(.) = 5 or string-length(.) = 9) or .[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(.,'[') or contains(.,']') or .[matches(.,'[A-Za-z]')])">
              <as:Attribute name="expressionLanguage" makeOptional_1="true" makeNillable_2="xsd" />
            </as:Element>
          </as:Element>
          <as:Element name="star:CustomerInformation" makeRepeatable="//star:GetCustomerInformationDataArea/star:CustomerInformation">
            <as:Element name="star:CustomerInformationHeader" printMessage_1="The TransactionTypeCode element in the CustomerInformationHeader component must have the value 'SC'.?not(./star:TransactionTypeCode[matches(.,'^SC$')])">
              <as:Element name="star:DocumentDateTime" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Element name="star:SecondaryPassword" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:SecondaryDealerNumberID" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:DocumentIdentificationGroup" makeMandatory="true">
                <as:Element name="star:DocumentIdentification" printMessage_1="The DocumentID element must contain a GUID.?not(string-length(./star:DocumentID) = 36 or string-length(./star:DocumentID) = 45) or              ./star:DocumentID[matches(.,'[ *,.;=+_?#$%@\^\\/!&gt;|}{()]')] or contains(./star:DocumentID,'[') or contains(./star:DocumentID,']')" printMessage_2="The DocumentID element value must match the BODID element value.?not(./star:DocumentID = //star:BODID)">
                  <as:Element name="star:DocumentID" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:AgencyRoleCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:AlternateDocumentIdentification" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:DocumentIdentificationGroup/star:AlternateDocumentIdentification">
                  <as:Element name="star:DocumentID" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:AgencyRoleCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
              </as:Element>
              <as:Element name="star:TransactionTypeCode" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:EmployeePerson" makeOptional_1="true" makeNillable_2="xsd">
                <as:Element name="star:AlternatePartyDocument" makeRepeatable="//star:EmployeePerson/star:AlternatePartyDocument" makeOptional_2="true" makeNillable_3="xsd">
                  <as:Element name="star:DocumentID" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DocumentType" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:IssuingName" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:EffectivePeriod" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                    </as:Element>
                    <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:SpecifiedPerson" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Element name="star:ID" makeRepeatable="//star:SpecifiedPerson/star:ID" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:GivenName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:GivenName">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:Alias" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:MiddleName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:FamilyName" makeRepeatable="//star:SpecifiedPerson/star:FamilyName" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:Title" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:Salutation" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:NameSuffix" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:MaritalStatusCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:GenderCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:BirthDate" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:AgeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                  </as:Element>
                  <as:Element name="star:MaidenName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:PreferredName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ResidenceAddress" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:AddressID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AddressType" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AttentionOf" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:ResidenceAddress/star:AttentionOf">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CareOf" makeRepeatable="//star:ResidenceAddress/star:CareOf" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineOne" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineTwo" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CitySub-DivisionName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:ResidenceAddress/star:CitySub-DivisionName">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CityName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CountryID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:Postcode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountyCountrySub-Division" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AddressUpdateDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:TelephoneCommunication" makeRepeatable="//star:SpecifiedPerson/star:TelephoneCommunication" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:FaxCommunication" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:URICommunication" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:URICommunication">
                    <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:NationalityCountryID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:LanguageCode" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:LanguageCode" />
                  <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:OriginalContactMethodTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:SpecifiedOccupation" makeNillable_1="xsd" makeRepeatable="//star:SpecifiedPerson/star:SpecifiedOccupation" makeOptional_3="true">
                    <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Title" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:SpecifiedOccupation/star:Title">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:Description" makeOptional_1="true" makeRepeatable="//star:SpecifiedOccupation/star:Description" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ClassCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:RankingCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:FullTimeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:PeriodHeld" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:Trait" makeOptional_1="true" makeRepeatable="//star:SpecifiedPerson/star:Trait" makeNillable_3="xsd">
                    <as:Element name="star:TraitText" makeOptional_1="true" makeRepeatable="//star:Trait/star:TraitText" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:TraitGroupCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:TraitTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:CustomerStatusCode" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DateOfBirthToleranceNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:HireDate" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:PreferredLanguageCode" makeNillable_1="xsd" makeOptional_2="true" />
              </as:Element>
            </as:Element>
            <as:Element name="star:CustomerInformationDetail" makeMandatory="true">
              <as:Element name="star:CustomerRoleToVehicleCode" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:CustomerTypeCode" makeRepeatable="//star:CustomerInformationDetail/star:CustomerTypeCode" makeNillable_2="xsd" makeOptional_3="true">
                <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:CustomerParty" makeMandatory="true">
                <as:Element name="star:PartyID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:LocationID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:DealerManagementSystemID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:AuthorizationID" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:RelationshipTypeCode" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:SpecialRemarksDescription" makeRepeatable="//star:CustomerParty/star:SpecialRemarksDescription" makeOptional_2="true" makeNillable_3="xsd">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:AlternatePartyDocument" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:CustomerParty/star:AlternatePartyDocument">
                  <as:Element name="star:DocumentID" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DocumentType" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:IssuingName" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:EffectivePeriod" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                    </as:Element>
                    <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:SpecifiedOrganization" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Element name="star:BusinessTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:CompanyName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:OrganizationID" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DistrictID" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:BranchCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CompanyCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DivisionCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:ServiceCenterCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:HoldingCompanyName" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:PrimaryContact" makeRepeatable="//star:SpecifiedOrganization/star:PrimaryContact" makeOptional_2="true" makeNillable_3="xsd">
                    <as:Element name="star:ID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:JobTitle" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:Responsibility" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:DepartmentName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:PersonName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:SpecifiedPerson" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:ID" makeRepeatable="//star:SpecifiedPerson/star:ID" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:GivenName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:GivenName">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Alias" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:MiddleName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:FamilyName" makeRepeatable="//star:SpecifiedPerson/star:FamilyName" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Title" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:Salutation" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:NameSuffix" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:MaritalStatusCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:GenderCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:BirthDate" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:AgeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:MaidenName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:PreferredName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ResidenceAddress" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:AddressID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AddressType" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AttentionOf" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:ResidenceAddress/star:AttentionOf">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CareOf" makeRepeatable="//star:ResidenceAddress/star:CareOf" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineOne" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineTwo" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CitySub-DivisionName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:ResidenceAddress/star:CitySub-DivisionName">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CityName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CountryID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:Postcode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountyCountrySub-Division" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AddressUpdateDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:TelephoneCommunication" makeRepeatable="//star:SpecifiedPerson/star:TelephoneCommunication" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:FaxCommunication" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:URICommunication" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:URICommunication">
                        <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:NationalityCountryID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:LanguageCode" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:LanguageCode" />
                      <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:OriginalContactMethodTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:SpecifiedOccupation" makeNillable_1="xsd" makeRepeatable="//star:SpecifiedPerson/star:SpecifiedOccupation" makeOptional_3="true">
                        <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Title" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:SpecifiedOccupation/star:Title">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:Description" makeOptional_1="true" makeRepeatable="//star:SpecifiedOccupation/star:Description" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ClassCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:RankingCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:FullTimeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PeriodHeld" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:Trait" makeOptional_1="true" makeRepeatable="//star:SpecifiedPerson/star:Trait" makeNillable_3="xsd">
                        <as:Element name="star:TraitText" makeOptional_1="true" makeRepeatable="//star:Trait/star:TraitText" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:TraitGroupCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:TraitTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:CustomerStatusCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:DateOfBirthToleranceNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:TelephoneCommunication" makeOptional_1="true" makeRepeatable="//star:PrimaryContact/star:TelephoneCommunication" makeNillable_3="xsd">
                      <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                          <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                        <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:PostalAddress" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:FaxCommunication" makeRepeatable="//star:PrimaryContact/star:FaxCommunication" makeNillable_2="xsd" makeOptional_3="true">
                      <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                          <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                        <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:URICommunication" makeRepeatable="//star:PrimaryContact/star:URICommunication" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                          <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                        <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:DoingBusinessAsName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:LegalClassificationCode" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:InceptionDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:NumberOfEmployeesNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:SpecifiedPerson" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Element name="star:ID" makeRepeatable="//star:SpecifiedPerson/star:ID" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:GivenName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:GivenName">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:Alias" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:MiddleName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:FamilyName" makeRepeatable="//star:SpecifiedPerson/star:FamilyName" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:Title" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:Salutation" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:NameSuffix" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:MaritalStatusCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:GenderCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:BirthDate" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:AgeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                  </as:Element>
                  <as:Element name="star:MaidenName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:PreferredName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ResidenceAddress" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:AddressID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AddressType" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AttentionOf" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:ResidenceAddress/star:AttentionOf">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CareOf" makeRepeatable="//star:ResidenceAddress/star:CareOf" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineOne" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineTwo" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CitySub-DivisionName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:ResidenceAddress/star:CitySub-DivisionName">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CityName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CountryID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:Postcode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountyCountrySub-Division" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AddressUpdateDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:TelephoneCommunication" makeRepeatable="//star:SpecifiedPerson/star:TelephoneCommunication" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:FaxCommunication" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:URICommunication" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:URICommunication">
                    <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:NationalityCountryID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:LanguageCode" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:LanguageCode" />
                  <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:OriginalContactMethodTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:SpecifiedOccupation" makeNillable_1="xsd" makeRepeatable="//star:SpecifiedPerson/star:SpecifiedOccupation" makeOptional_3="true">
                    <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Title" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:SpecifiedOccupation/star:Title">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:Description" makeOptional_1="true" makeRepeatable="//star:SpecifiedOccupation/star:Description" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ClassCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:RankingCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:FullTimeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:PeriodHeld" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:Trait" makeOptional_1="true" makeRepeatable="//star:SpecifiedPerson/star:Trait" makeNillable_3="xsd">
                    <as:Element name="star:TraitText" makeOptional_1="true" makeRepeatable="//star:Trait/star:TraitText" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:TraitGroupCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:TraitTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:CustomerStatusCode" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DateOfBirthToleranceNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:CustomerParty/star:Privacy">
                  <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                    </as:Element>
                    <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:PreferredLanguageCode" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:ManufacturerCustomerID" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ManufacturerHouseholdID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:PartyActionEvent" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:CustomerParty/star:PartyActionEvent">
                  <as:Element name="star:EventID" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:EventTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:EventDescription" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:EventOccurrenceDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:DealerIndicator" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:VehicleID" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
              </as:Element>
              <as:Element name="star:OwnershipStartDate" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Element name="star:OwnershipEndDate" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Element name="star:Vehicle" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:CustomerInformationDetail/star:Vehicle">
                <as:Element name="star:Model" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ModelYear" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:ModelDescription" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:Vehicle/star:ModelDescription">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:MakeString" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:SaleClassCode" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:Condition" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:VehicleNote" makeRepeatable="//star:Vehicle/star:VehicleNote" makeOptional_2="true" makeNillable_3="xsd">
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:TrimCode" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:DoorsQuantityNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:BodyStyle" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:TransmissionGroup" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Element name="star:TransmissionCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:TransmissionTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:TransmissionTypeName" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:ColorGroup" makeOptional_1="true" makeRepeatable="//star:Vehicle/star:ColorGroup" makeNillable_3="xsd">
                  <as:Element name="star:ColorItemCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:ManufacturerColorCode" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ColorDescription" makeOptional_1="true" makeRepeatable="//star:ColorGroup/star:ColorDescription" makeNillable_3="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ColorName" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ColorCodeChangeIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:VehicleClassCode" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:FuelTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Element name="star:DriveTrain" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:DriveTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:VehiclePassengersNumeric" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:Engine" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Element name="star:MakeString" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:ModelDescription" makeRepeatable="//star:Engine/star:ModelDescription" makeOptional_2="true" makeNillable_3="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ModelYear" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:SaleClassCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:Condition" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:Model" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:VehicleStockString" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:ColorGroup" makeRepeatable="//star:Engine/star:ColorGroup" makeOptional_2="true" makeNillable_3="xsd">
                    <as:Element name="star:ColorItemCode" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Element name="star:ManufacturerColorCode" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ColorDescription" makeOptional_1="true" makeRepeatable="//star:ColorGroup/star:ColorDescription" makeNillable_3="xsd">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ColorName" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ColorCodeChangeIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:BoatEngineTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:FuelTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:FullThrottleOperatingRangeMaximumMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:IdleRevolutionPerMinuteForwardGearMinimumMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:AlternatorOutputMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:BatterySizeRequirementsMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:CurrentDrawMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:PeakThrustMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:BoreMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:StrokeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CylinderConfigurationCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:NumberOfEngineCylindersNumeric" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:FuelInductionSystemCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:BoatEngineLocationCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:FuelConsumptionMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="volumeUnitCode" makeMandatory="true" />
                    <as:Attribute name="timeUnitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:TotalEngineHoursNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:PowerTrimIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:StartingSystemTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:IgnitionSystem" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:LubricationSystem" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CoolingSystem" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:Emissions" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:SteeringSystem" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:PropellerType" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:GeneralEngineDescription" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:Engine/star:GeneralEngineDescription">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:DetailedEngineDescription" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:Engine/star:DetailedEngineDescription">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DriveTransmissionDescription" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:Engine/star:DriveTransmissionDescription">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:EngineSerialString" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:DriveSerialString" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:TransomShieldKitSerialString" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:VDriveSerialString" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:TransmissionSerialString" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:DryWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:WetWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ShaftLengthMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:EffectiveMeanPressureMeasure" makeRepeatable="//star:Engine/star:EffectiveMeanPressureMeasure" makeNillable_2="xsd" makeOptional_3="true">
                    <as:Element name="star:PressureMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:SpeedMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ElectricityMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:MechanicalEnergyMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:EffectiveMeanPressureMeasure/star:LocationName">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:PowerMeasure" makeNillable_1="xsd" makeRepeatable="//star:Engine/star:PowerMeasure" makeOptional_3="true">
                    <as:Element name="star:PressureMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:SpeedMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ElectricityMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:MechanicalEnergyMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:PowerMeasure/star:LocationName">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:MeanPistonSpeedMeasure" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:Engine/star:MeanPistonSpeedMeasure">
                    <as:Element name="star:PressureMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:SpeedMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ElectricityMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:MechanicalEnergyMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationName" makeRepeatable="//star:MeanPistonSpeedMeasure/star:LocationName" makeNillable_2="xsd" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:CompressionPressureMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:TorqueMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:PressureMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:SpeedMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:ElectricityMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:MechanicalEnergyMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationName" makeNillable_1="xsd" makeRepeatable="//star:TorqueMeasure/star:LocationName" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:GearRatioGroup" makeRepeatable="//star:Engine/star:GearRatioGroup" makeOptional_2="true" makeNillable_3="xsd">
                    <as:Element name="star:GearRatio" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:GearRatioDescription" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:GearRatioGroup/star:GearRatioDescription">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:EngineDimensions" makeOptional_1="true" makeRepeatable="//star:Engine/star:EngineDimensions" makeNillable_3="xsd">
                    <as:Element name="star:EngineDimensionDescription" makeRepeatable="//star:EngineDimensions/star:EngineDimensionDescription" makeNillable_2="xsd" makeOptional_3="true">
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:EngineHeightMeasure" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:EngineWidthMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:EngineDepthMeasure" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="unitCode" makeMandatory="true" />
                      <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                  </as:Element>
                  <as:Element name="star:DisplacementMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:OperatingVoltageMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CompressionRatioMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:VehicleID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:AxleCode" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ManufacturerName" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:VehicleWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:GrossWeightMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:UnloadedVehicleWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ModelGroup" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ModelYearChangeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:DistributorModelCode" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:ModelClass" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:RegistrationID" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:VehicleLengthMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:Chassis" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Element name="star:ChassisMake" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:ChassisModel" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:SeriesCode" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:SeriesName" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:VehicleStockString" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Element name="star:VehicleDescription" makeRepeatable="//star:Vehicle/star:VehicleDescription" makeNillable_2="xsd" makeOptional_3="true">
                  <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:DryWeightMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:WetWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:Tank" makeOptional_1="true" makeRepeatable="//star:Vehicle/star:Tank" makeNillable_3="xsd">
                  <as:Element name="star:TankUsageCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:TankMaterialCode" makeOptional_1="true" makeNillable_2="xsd" />
                  <as:Element name="star:TankCapacityMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:TankCountNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:UsagePreference" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                      <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                  </as:Element>
                </as:Element>
                <as:Element name="star:MaximumSpeedMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:VehicleDimension" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Element name="star:DimensionValueMeasure" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DimensionTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                    <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:DimensionDescription" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:WidthMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:LengthMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                  </as:Element>
                  <as:Element name="star:HeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:DiameterMeasure" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                </as:Element>
                <as:Element name="star:WheelBaseMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:TurningRadiusMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:GroundClearanceMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:SeatHeightMeasure" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:TowingCapacityWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
                <as:Element name="star:CertificationGroup" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Element name="star:CertificationIssuerName" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CertificationValue" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:CertificationDate" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:CertifiedWarrantyCode" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ActualOdometer" makeNillable_1="xsd" makeOptional_2="true">
                    <as:Attribute name="unitCode" makeMandatory="true" />
                    <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:VehiclePreviousUseCode" makeNillable_1="xsd" makeOptional_2="true" />
                  <as:Element name="star:PreviousOwnerParty" makeOptional_1="true" makeNillable_2="xsd">
                    <as:Element name="star:PartyID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:LocationID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:DealerManagementSystemID" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:AuthorizationID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:RelationshipTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:SpecialRemarksDescription" makeNillable_1="xsd" makeRepeatable="//star:PreviousOwnerParty/star:SpecialRemarksDescription" makeOptional_3="true">
                      <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:AlternatePartyDocument" makeNillable_1="xsd" makeRepeatable="//star:PreviousOwnerParty/star:AlternatePartyDocument" makeOptional_3="true">
                      <as:Element name="star:DocumentID" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:DocumentType" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:IssuingName" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:EffectivePeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:SpecifiedOrganization" makeOptional_1="true" makeNillable_2="xsd">
                      <as:Element name="star:BusinessTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:CompanyName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:OrganizationID" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:DistrictID" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:BranchCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:CompanyCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:DivisionCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:ServiceCenterCode" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:HoldingCompanyName" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:PrimaryContact" makeRepeatable="//star:SpecifiedOrganization/star:PrimaryContact" makeOptional_2="true" makeNillable_3="xsd">
                        <as:Element name="star:ID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:JobTitle" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:Responsibility" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:DepartmentName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:PersonName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:SpecifiedPerson" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:ID" makeRepeatable="//star:SpecifiedPerson/star:ID" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:GivenName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:GivenName">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:Alias" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:MiddleName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:FamilyName" makeRepeatable="//star:SpecifiedPerson/star:FamilyName" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:Title" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:Salutation" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:NameSuffix" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:MaritalStatusCode" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:GenderCode" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:BirthDate" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:AgeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:MaidenName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:PreferredName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ResidenceAddress" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:AddressID" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AddressType" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AttentionOf" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:ResidenceAddress/star:AttentionOf">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CareOf" makeRepeatable="//star:ResidenceAddress/star:CareOf" makeOptional_2="true" makeNillable_3="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineOne" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineTwo" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CitySub-DivisionName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:ResidenceAddress/star:CitySub-DivisionName">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CityName" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CountryID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:Postcode" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CountyCountrySub-Division" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:AddressUpdateDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                              </as:Element>
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:TelephoneCommunication" makeRepeatable="//star:SpecifiedPerson/star:TelephoneCommunication" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                              <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                                <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                            </as:Element>
                            <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                              <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                              </as:Element>
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:FaxCommunication" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                              <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                                <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                            </as:Element>
                            <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                              <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                              </as:Element>
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:URICommunication" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:URICommunication">
                            <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                              <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                                <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                              </as:Element>
                            </as:Element>
                            <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                              <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                              </as:Element>
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:NationalityCountryID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:LanguageCode" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:LanguageCode" />
                          <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                  <as:Attribute name="unitCode" makeMandatory="true" />
                                </as:Element>
                                <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                                <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                                <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                              </as:Element>
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:OriginalContactMethodTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:SpecifiedOccupation" makeNillable_1="xsd" makeRepeatable="//star:SpecifiedPerson/star:SpecifiedOccupation" makeOptional_3="true">
                            <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:Title" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:SpecifiedOccupation/star:Title">
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:Description" makeOptional_1="true" makeRepeatable="//star:SpecifiedOccupation/star:Description" makeNillable_3="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:ClassCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:RankingCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:FullTimeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PeriodHeld" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:Trait" makeOptional_1="true" makeRepeatable="//star:SpecifiedPerson/star:Trait" makeNillable_3="xsd">
                            <as:Element name="star:TraitText" makeOptional_1="true" makeRepeatable="//star:Trait/star:TraitText" makeNillable_3="xsd">
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                            <as:Element name="star:TraitGroupCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:TraitTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:CustomerStatusCode" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:DateOfBirthToleranceNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:TelephoneCommunication" makeOptional_1="true" makeRepeatable="//star:PrimaryContact/star:TelephoneCommunication" makeNillable_3="xsd">
                          <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                              <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                            <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:PostalAddress" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:FaxCommunication" makeRepeatable="//star:PrimaryContact/star:FaxCommunication" makeNillable_2="xsd" makeOptional_3="true">
                          <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                              <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                            <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:URICommunication" makeRepeatable="//star:PrimaryContact/star:URICommunication" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                          <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                            <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                              <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                            </as:Element>
                          </as:Element>
                          <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                            <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                                <as:Attribute name="unitCode" makeMandatory="true" />
                              </as:Element>
                              <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                              <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                              <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                            </as:Element>
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:DoingBusinessAsName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:LegalClassificationCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:InceptionDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:NumberOfEmployeesNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:SpecifiedPerson" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Element name="star:ID" makeRepeatable="//star:SpecifiedPerson/star:ID" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:GivenName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:GivenName">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Alias" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:MiddleName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:FamilyName" makeRepeatable="//star:SpecifiedPerson/star:FamilyName" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:Title" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:Salutation" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:NameSuffix" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:MaritalStatusCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:GenderCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:BirthDate" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:AgeMeasure" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="unitCode" makeMandatory="true" />
                      </as:Element>
                      <as:Element name="star:MaidenName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:PreferredName" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:ResidenceAddress" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:AddressID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AddressType" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AttentionOf" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:ResidenceAddress/star:AttentionOf">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CareOf" makeRepeatable="//star:ResidenceAddress/star:CareOf" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineOne" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineTwo" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CitySub-DivisionName" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:ResidenceAddress/star:CitySub-DivisionName">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CityName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CountryID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:Postcode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountyCountrySub-Division" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AddressUpdateDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:TelephoneCommunication" makeRepeatable="//star:SpecifiedPerson/star:TelephoneCommunication" makeNillable_2="xsd" makeOptional_3="true">
                        <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:TelephoneCommunication/star:Privacy">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:FaxCommunication" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Element name="star:URIID" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeOptional_1="true" makeRepeatable="//star:FaxCommunication/star:Privacy" makeNillable_3="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:URICommunication" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:URICommunication">
                        <as:Element name="star:URIID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:ChannelCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LocalNumber" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CompleteNumber" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountryNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ExtensionNumber" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AreaNumberCode" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Access" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:UseCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ServiceProviderName" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:HTMLPreferredIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:UsagePreference" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PriorityRankingNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:PreferredIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:UnavailablePeriod" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                          <as:Element name="star:AvailablePeriod" makeRepeatable="//star:UsagePreference/star:AvailablePeriod" makeNillable_2="xsd" makeOptional_3="true">
                            <as:Element name="star:DurationMeasure" makeOptional_1="true" makeNillable_2="xsd">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:StartDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:EndDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:DayOfWeekCode" makeOptional_1="true" makeNillable_2="xsd" />
                          </as:Element>
                        </as:Element>
                        <as:Element name="star:Privacy" makeRepeatable="//star:URICommunication/star:Privacy" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:NationalityCountryID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:ContactMethodTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:LanguageCode" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:SpecifiedPerson/star:LanguageCode" />
                      <as:Element name="star:PostalAddress" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:AddressID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AddressType" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:AttentionOf" makeRepeatable="//star:PostalAddress/star:AttentionOf" makeOptional_2="true" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CareOf" makeNillable_1="xsd" makeRepeatable="//star:PostalAddress/star:CareOf" makeOptional_3="true">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineOne" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineTwo" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineThree" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:LineFour" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:LineFive" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CitySub-DivisionName" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:PostalAddress/star:CitySub-DivisionName">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CityName" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:CountryID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:Postcode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:StateOrProvinceCountrySub-DivisionID" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:CountyCountrySub-Division" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:AddressUpdateDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:Privacy" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                            <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                              <as:Attribute name="unitCode" makeMandatory="true" />
                            </as:Element>
                            <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                            <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                            <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                          </as:Element>
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:OriginalContactMethodTypeCode" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:SpecifiedOccupation" makeNillable_1="xsd" makeRepeatable="//star:SpecifiedPerson/star:SpecifiedOccupation" makeOptional_3="true">
                        <as:Element name="star:TypeCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:Title" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:SpecifiedOccupation/star:Title">
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:Description" makeOptional_1="true" makeRepeatable="//star:SpecifiedOccupation/star:Description" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:ClassCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:RankingCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:FullTimeIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:PeriodHeld" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                            <as:Attribute name="unitCode" makeMandatory="true" />
                          </as:Element>
                          <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:CompleteDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Element name="star:OpenIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:Trait" makeOptional_1="true" makeRepeatable="//star:SpecifiedPerson/star:Trait" makeNillable_3="xsd">
                        <as:Element name="star:TraitText" makeOptional_1="true" makeRepeatable="//star:Trait/star:TraitText" makeNillable_3="xsd">
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        </as:Element>
                        <as:Element name="star:TraitGroupCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                        <as:Element name="star:TraitTypeCode" makeOptional_1="true" makeNillable_2="xsd">
                          <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                          <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                          <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                        </as:Element>
                      </as:Element>
                      <as:Element name="star:CustomerStatusCode" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="listID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listVersionID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="name" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="listURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="listSchemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:DateOfBirthToleranceNumeric" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:Privacy" makeNillable_1="xsd" makeOptional_2="true" makeRepeatable="//star:PreviousOwnerParty/star:Privacy">
                      <as:Element name="star:PrivacyIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyTypeString" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Element name="star:PrivacyPeriod" makeOptional_1="true" makeNillable_2="xsd">
                        <as:Element name="star:DurationMeasure" makeNillable_1="xsd" makeOptional_2="true">
                          <as:Attribute name="unitCode" makeMandatory="true" />
                        </as:Element>
                        <as:Element name="star:InclusiveIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:StartDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:EndDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:CompleteDateTime" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Element name="star:OpenIndicator" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Element name="star:DayOfWeekCode" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                    </as:Element>
                    <as:Element name="star:PreferredLanguageCode" makeNillable_1="xsd" makeOptional_2="true" />
                    <as:Element name="star:ManufacturerCustomerID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeNillable_1="xsd" makeOptional_2="true" />
                    </as:Element>
                    <as:Element name="star:ManufacturerHouseholdID" makeNillable_1="xsd" makeOptional_2="true">
                      <as:Attribute name="schemeID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                      <as:Attribute name="schemeAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeDataURI" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:PartyActionEvent" makeOptional_1="true" makeRepeatable="//star:PreviousOwnerParty/star:PartyActionEvent" makeNillable_3="xsd">
                      <as:Element name="star:EventID" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="schemeID" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeName" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeAgencyName" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                        <as:Attribute name="schemeDataURI" makeOptional_1="true" makeNillable_2="xsd" />
                        <as:Attribute name="schemeURI" makeOptional_1="true" makeNillable_2="xsd" />
                      </as:Element>
                      <as:Element name="star:EventTypeCode" makeNillable_1="xsd" makeOptional_2="true" />
                      <as:Element name="star:EventDescription" makeNillable_1="xsd" makeOptional_2="true">
                        <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                      </as:Element>
                      <as:Element name="star:EventOccurrenceDateTime" makeOptional_1="true" makeNillable_2="xsd" />
                    </as:Element>
                    <as:Element name="star:DealerIndicator" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:ClassAndWarranty" makeOptional_1="true" makeNillable_2="xsd" makeRepeatable="//star:CertificationGroup/star:ClassAndWarranty">
                    <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                  </as:Element>
                  <as:Element name="star:RepairOrderNumber" makeRepeatable="//star:CertificationGroup/star:RepairOrderNumber" makeNillable_2="xsd" makeOptional_3="true" />
                </as:Element>
                <as:Element name="star:PayloadCapacityWeightMeasure" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:InteriorDescription" makeNillable_1="xsd" makeOptional_2="true">
                  <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:FrontAxleWeight" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeOptional_1="true" makeNillable_2="xsd" />
                </as:Element>
                <as:Element name="star:RearAxleWeight" makeOptional_1="true" makeNillable_2="xsd">
                  <as:Attribute name="unitCode" makeMandatory="true" />
                  <as:Attribute name="qualifierCode" makeNillable_1="xsd" makeOptional_2="true" />
                </as:Element>
              </as:Element>
            </as:Element>
            <as:Element name="star:CustomerInformationRewardsCard" makeNillable_1="xsd" makeOptional_2="true">
              <as:Element name="star:CardType" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Element name="star:EarningsAsOfDate" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Element name="star:EarningsAvailableForRedemption" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="currencyID" makeMandatory="true" />
              </as:Element>
              <as:Element name="star:OfferURI" makeOptional_1="true" makeNillable_2="xsd" />
              <as:Element name="star:BonusEarningCode" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
              </as:Element>
              <as:Element name="star:IncentiveCode" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="listID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyID" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listAgencyName" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listName" makeOptional_1="true" makeNillable_2="xsd" />
                <as:Attribute name="listVersionID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="name" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="languageID" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listURI" makeNillable_1="xsd" makeOptional_2="true" />
                <as:Attribute name="listSchemeURI" makeNillable_1="xsd" makeOptional_2="true" />
              </as:Element>
              <as:Element name="star:OfferAmount" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="currencyID" makeMandatory="true" />
              </as:Element>
              <as:Element name="star:OfferDetails" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="languageID" makeOptional_1="true" makeNillable_2="xsd" />
              </as:Element>
              <as:Element name="star:OfferExpirationDate" makeNillable_1="xsd" makeOptional_2="true" />
              <as:Element name="star:TotalEarnings" makeOptional_1="true" makeNillable_2="xsd">
                <as:Attribute name="currencyID" makeMandatory="true" />
              </as:Element>
              <as:Element name="star:TotalEarningsForRedemption" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="currencyID" makeMandatory="true" />
              </as:Element>
              <as:Element name="star:VehicleRedemptionAllowance" makeNillable_1="xsd" makeOptional_2="true">
                <as:Attribute name="currencyID" makeMandatory="true" />
              </as:Element>
            </as:Element>
          </as:Element>
        </as:Element>
      </as:Element>
    </as:Structure>
  </as:AssemblyStructure>
</as:CAM>