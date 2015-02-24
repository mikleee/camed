<as:CAM
        xmlns:as="http://www.oasis-open.org/committees/cam"
        xmlns:camed="http://jcam.org.uk/editor"
        xmlns:xsd="http://www.w3.org/2001/XMLSchema" compiled="true" CAMlevel="1" version="1.0">
    <as:Header>
        <as:Description>Ford UDB File</as:Description>
        <as:Owner>Motive Retail LLC</as:Owner>
        <as:Version>3.21R+</as:Version>
        <as:DateTime>2013-02-11T09:33:49</as:DateTime>
    </as:Header>
    <as:Namespaces>
        <as:namespace prefix="xsd">http://www.w3.org/2001/XMLSchema</as:namespace>
        <as:namespace prefix="as">http://www.oasis-open.org/committees/cam</as:namespace>
        <as:namespace prefix="xml">http://www.w3.org/XML/1998/namespace</as:namespace>
        <as:namespace prefix="camed">http://jcam.org.uk/editor</as:namespace>
    </as:Namespaces>
    <as:AssemblyStructure>
        <as:Structure ID="UDBFile" reference="" taxonomy="XML">
            <as:Element name="UDBFile" makeMandatory="true">
                <as:Attribute name="version" makeMandatory="true"/>
                <as:Element name="ERROR" makeOptional_1="true" makeRepeatable="//UDBFile/ERROR">
                    <as:Attribute name="errorType" makeMandatory="true"/>
                    <as:Attribute name="errorClass" makeMandatory="true"/>
                    <as:Attribute name="foundHeaderPosition" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerPosition" makeOptional_1="true"/>
                    <as:Attribute name="lineCount" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderRecordCount" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerRecordCount" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderFileDate" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderFileDate-2" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerFileDate" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderFileNumber" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderFileNumber-2" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerFileNumber" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderPACode" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerPACode" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderSubDealerPACode" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerSubDealerPACode" makeOptional_1="true"/>
                    <as:Attribute name="foundHeaderGeographicSalesAreaCode" makeOptional_1="true"/>
                    <as:Attribute name="foundTrailerGeographicSalesAreaCode" makeOptional_1="true"/>
                    <as:Attribute name="foundLineLength" makeOptional_1="true"/>
                    <as:Attribute name="possibleLineLength" makeOptional_1="true"/>
                    <as:Attribute name="foundRecordType" makeOptional_1="true"/>
                    <as:Attribute name="possibleRecordType" makeOptional_1="true"/>
                    <as:Attribute name="foundPrecedeFileLineRecordType" makeOptional_1="true"/>
                    <as:Attribute name="foundDate" makeOptional_1="true"/>
                    <as:Element name="ERROR" makeRepeatable="//ERROR/ERROR" makeOptional_2="true">
                        <as:Attribute name="errorType" makeMandatory="true"/>
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="errorClass" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="FileHeader" makeRepeatable="//ERROR/FileHeader" makeOptional_2="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="PACode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL01" makeMandatory="true"/>
                        <as:Element name="FILECONTROL02" makeMandatory="true"/>
                        <as:Element name="FILECONTROL03" makeMandatory="true"/>
                        <as:Element name="FILECONTROL04" makeMandatory="true"/>
                        <as:Element name="FileDate" makeMandatory="true"/>
                        <as:Element name="FileNumber" makeMandatory="true"/>
                        <as:Element name="FILECONTROL05" makeMandatory="true"/>
                        <as:Element name="FILECONTROL06" makeMandatory="true"/>
                        <as:Element name="FILECONTROL05-2" makeMandatory="true"/>
                        <as:Element name="FILECONTROL07" makeMandatory="true"/>
                        <as:Element name="FILECONTROL08" makeMandatory="true"/>
                        <as:Element name="FileDate-2" makeMandatory="true"/>
                        <as:Element name="FileNumber-2" makeMandatory="true"/>
                        <as:Element name="RecordCount" makeMandatory="true"/>
                        <as:Element name="SubDealerPACode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL09" makeMandatory="true"/>
                        <as:Element name="FILECONTROL10" makeMandatory="true"/>
                        <as:Element name="FILECONTROL11" makeMandatory="true"/>
                        <as:Element name="GeographicSalesAreaCode" makeMandatory="true"/>
                        <as:Element name="FranchiseCode" makeMandatory="true"/>
                        <as:Element name="DSPSoftwareReleaseVersion" makeMandatory="true"/>
                        <as:Element name="FILECONTROL12" makeMandatory="true"/>
                        <as:Element name="FILECONTROL13" makeMandatory="true"/>
                        <as:Element name="FILECONTROL14" makeMandatory="true"/>
                        <as:Element name="FILECONTROL02-2" makeMandatory="true"/>
                        <as:Element name="FILECONTROL15" makeMandatory="true"/>
                        <as:Element name="VendorID" makeMandatory="true"/>
                        <as:Element name="FileTypeFlag" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="RepairOrderHeader" makeRepeatable="//ERROR/RepairOrderHeader" makeOptional_2="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Attribute name="currentFileDate" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="VIN" makeMandatory="true"/>
                        <as:Element name="RONumber" makeMandatory="true"/>
                        <as:Element name="ROXRef" makeMandatory="true"/>
                        <as:Element name="FILECONTROL17" makeMandatory="true"/>
                        <as:Element name="ROOpenDate" makeMandatory="true">
                            <as:Attribute name="truncROOpenDate" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="ROCloseDate" makeMandatory="true">
                            <as:Attribute name="truncROCloseDate" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="OdometerReading" makeMandatory="true"/>
                        <as:Element name="OdometerIndicator" makeMandatory="true"/>
                        <as:Element name="FirstName" makeMandatory="true"/>
                        <as:Element name="MiddleInitial" makeMandatory="true"/>
                        <as:Element name="LastName" makeMandatory="true"/>
                        <as:Element name="Title" makeMandatory="true"/>
                        <as:Element name="AddressLine1" makeMandatory="true"/>
                        <as:Element name="AddressLine2" makeMandatory="true"/>
                        <as:Element name="City" makeMandatory="true"/>
                        <as:Element name="StateOrProvince" makeMandatory="true"/>
                        <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                        <as:Element name="HomePhone" makeMandatory="true"/>
                        <as:Element name="WorkPhone" makeMandatory="true"/>
                        <as:Element name="NetCustomerPaidAmount" makeMandatory="true"/>
                        <as:Element name="TaxAmount" makeMandatory="true"/>
                        <as:Element name="LicensePlateNumber" makeMandatory="true"/>
                        <as:Element name="RepairOrderOpenTime" makeMandatory="true"/>
                        <as:Element name="RepairOrderCloseTime" makeMandatory="true"/>
                        <as:Element name="AppointmentTypeCode" makeMandatory="true"/>
                        <as:Element name="AppointmentInitiatedDate" makeMandatory="true">
                            <as:Attribute name="truncApptInitDate" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="ServiceCustomerTypeCode" makeMandatory="true"/>
                        <as:Element name="ServiceWriterLocalID" makeMandatory="true"/>
                        <as:Element name="ServiceWriterNationalID" makeMandatory="true"/>
                        <as:Element name="CustomerEmail" makeMandatory="true"/>
                        <as:Element name="CellPhone" makeMandatory="true"/>
                        <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-2" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="RepairOrderService" makeRepeatable="//ERROR/RepairOrderService" makeOptional_2="true"
                                printMessage_3="Sublet / Miscellaneous #10 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription10)) and ./SubletOrMiscAmount10 = 0) or             (not(./SubletOrMiscAmount10 = 0) and not(string(normalize-space(./SubletOrMiscDescription10))))"
                                printMessage_4="Sublet / Miscellaneous #2 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription02)) and ./SubletOrMiscAmount02 = 0) or             (not(./SubletOrMiscAmount02 = 0) and not(string(normalize-space(./SubletOrMiscDescription02))))"
                                printMessage_5="Sublet / Miscellaneous #7 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription07)) and ./SubletOrMiscAmount07 = 0) or             (not(./SubletOrMiscAmount07 = 0) and not(string(normalize-space(./SubletOrMiscDescription07))))"
                                printMessage_6="Sublet / Miscellaneous #5 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription05)) and ./SubletOrMiscAmount05 = 0) or             (not(./SubletOrMiscAmount05 = 0) and not(string(normalize-space(./SubletOrMiscDescription05))))"
                                printMessage_7="Sublet / Miscellaneous #8 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription08)) and ./SubletOrMiscAmount08 = 0) or             (not(./SubletOrMiscAmount08 = 0) and not(string(normalize-space(./SubletOrMiscDescription08))))"
                                printMessage_8="Sublet / Miscellaneous #4 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription04)) and ./SubletOrMiscAmount04 = 0) or             (not(./SubletOrMiscAmount04 = 0) and not(string(normalize-space(./SubletOrMiscDescription04))))"
                                printMessage_9="Sublet / Miscellaneous #3 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription03)) and ./SubletOrMiscAmount03 = 0) or             (not(./SubletOrMiscAmount03 = 0) and not(string(normalize-space(./SubletOrMiscDescription03))))"
                                printMessage_10="Sublet / Miscellaneous #9 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription09)) and ./SubletOrMiscAmount09 = 0) or             (not(./SubletOrMiscAmount09 = 0) and not(string(normalize-space(./SubletOrMiscDescription09))))"
                                printMessage_11="Sublet / Miscellaneous Descriptions and Amounts must start at number 1 and be sent in order without skipping numbers.?             (string(normalize-space(./SubletOrMiscDescription02)) and not(string(normalize-space(./SubletOrMiscDescription01)))) or             (string(normalize-space(./SubletOrMiscDescription03)) and not(string(normalize-space(./SubletOrMiscDescription02)))) or             (string(normalize-space(./SubletOrMiscDescription04)) and not(string(normalize-space(./SubletOrMiscDescription03)))) or             (string(normalize-space(./SubletOrMiscDescription05)) and not(string(normalize-space(./SubletOrMiscDescription04)))) or             (string(normalize-space(./SubletOrMiscDescription05)) and not(string(normalize-space(./SubletOrMiscDescription05)))) or             (string(normalize-space(./SubletOrMiscDescription07)) and not(string(normalize-space(./SubletOrMiscDescription06)))) or             (string(normalize-space(./SubletOrMiscDescription08)) and not(string(normalize-space(./SubletOrMiscDescription07)))) or             (string(normalize-space(./SubletOrMiscDescription09)) and not(string(normalize-space(./SubletOrMiscDescription08)))) or             (string(normalize-space(./SubletOrMiscDescription10)) and not(string(normalize-space(./SubletOrMiscDescription09))))"
                                printMessage_12="Sublet / Miscellaneous #1 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription01)) and ./SubletOrMiscAmount01 = 0) or             (not(./SubletOrMiscAmount01 = 0) and not(string(normalize-space(./SubletOrMiscDescription01))))"
                                printMessage_13="Sublet / Miscellaneous #6 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription06)) and ./SubletOrMiscAmount06 = 0) or             (not(./SubletOrMiscAmount06 = 0) and not(string(normalize-space(./SubletOrMiscDescription06))))">
                        <as:Attribute name="awaID" makeOptional_1="true"/>
                        <as:Attribute name="bundledlaborID" makeOptional_1="true"/>
                        <as:Attribute name="menupriceID" makeOptional_1="true"/>
                        <as:Attribute name="espwarrantydeductible" makeOptional_1="true"/>
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="SequenceNumber" makeMandatory="true"/>
                        <as:Element name="RepairTypeCode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL17-2" makeMandatory="true"/>
                        <as:Element name="ServicingDepartmentCode" makeMandatory="true"/>
                        <as:Element name="LaborOperationCode" makeMandatory="true"/>
                        <as:Element name="LaborChargeAmount" makeMandatory="true"/>
                        <as:Element name="BilledHours" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription01" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription02" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription03" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription04" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription05" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription06" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription07" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription08" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription09" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscDescription10" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount01" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount02" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount03" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount04" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount05" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount06" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount07" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount08" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount09" makeMandatory="true"/>
                        <as:Element name="SubletOrMiscAmount10" makeMandatory="true"/>
                        <as:Element name="LaborDescription" makeMandatory="true">
                            <as:Element name="IsAWASplit" makeMandatory="true"/>
                            <as:Element name="AWAFordPercentage" makeNillable_1="true"/>
                            <as:Element name="AWADealerPercentage" makeNillable_1="true"/>
                            <as:Element name="AWACustomerPercentage" makeNillable_1="true"/>
                            <as:Element name="LaborDescriptionText" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="TechnicianLocalID" makeMandatory="true"/>
                        <as:Element name="TechnicianNationalID" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-3" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="RepairOrderPart" makeOptional_1="true" makeRepeatable="//ERROR/RepairOrderPart">
                        <as:Attribute name="awaID" makeOptional_1="true"/>
                        <as:Attribute name="bundledlaborID" makeOptional_1="true"/>
                        <as:Attribute name="partcoresaleID" makeOptional_1="true"/>
                        <as:Attribute name="partsreturn" makeOptional_1="true"/>
                        <as:Attribute name="partskitID" makeOptional_1="true"/>
                        <as:Attribute name="menupriceID" makeOptional_1="true"/>
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                        <as:Element name="PartNumberBase" makeMandatory="true"/>
                        <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                        <as:Element name="Quantity" makeMandatory="true"/>
                        <as:Element name="SaleAmount" makeMandatory="true"/>
                        <as:Element name="DealerCostAmount" makeMandatory="true"/>
                        <as:Element name="Description" makeMandatory="true">
                            <as:Element name="IsAWASplit" makeMandatory="true"/>
                            <as:Element name="AWAFordPercentage" makeOptional_1="true" makeNillable_2="true"/>
                            <as:Element name="AWADealerPercentage" makeNillable_1="true" makeOptional_2="true"/>
                            <as:Element name="AWACustomerPercentage" makeNillable_1="true" makeOptional_2="true"/>
                            <as:Element name="DescriptionText" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="CausalCode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL17-3" makeMandatory="true"/>
                        <as:Element name="CounterPersonLocalID" makeMandatory="true"/>
                        <as:Element name="CounterPersonNationalID" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-4" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="OTCPartInvoiceHeader" makeRepeatable="//ERROR/OTCPartInvoiceHeader" makeOptional_2="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Attribute name="currentFileDate" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="InvoiceNumber" makeMandatory="true"/>
                        <as:Element name="InvoiceDate" makeMandatory="true">
                            <as:Attribute name="truncInvoiceDate" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="LastName" makeMandatory="true"/>
                        <as:Element name="AddressLine1" makeMandatory="true"/>
                        <as:Element name="AddressLine2" makeMandatory="true"/>
                        <as:Element name="City" makeMandatory="true"/>
                        <as:Element name="StateOrProvince" makeMandatory="true"/>
                        <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                        <as:Element name="CustomerTypeCode" makeMandatory="true"/>
                        <as:Element name="CustomerTaxID" makeMandatory="true"/>
                        <as:Element name="TaxAmount" makeMandatory="true"/>
                        <as:Element name="FILECONTROL17-4" makeMandatory="true"/>
                        <as:Element name="CounterPersonLocalID" makeMandatory="true"/>
                        <as:Element name="CounterPersonNationalID" makeMandatory="true"/>
                        <as:Element name="FirstName" makeMandatory="true"/>
                        <as:Element name="MiddleInitial" makeMandatory="true"/>
                        <as:Element name="Title" makeMandatory="true"/>
                        <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                        <as:Element name="HomePhone" makeMandatory="true"/>
                        <as:Element name="WorkPhone" makeMandatory="true"/>
                        <as:Element name="CellPhone" makeMandatory="true"/>
                        <as:Element name="CustomerEmail" makeMandatory="true"/>
                        <as:Element name="DiscountAmount" makeMandatory="true"/>
                        <as:Element name="ShippingAmount" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-5" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="OTCPartsInvoicePart" makeRepeatable="//ERROR/OTCPartsInvoicePart" makeOptional_2="true">
                        <as:Attribute name="partcoresaleID" makeOptional_1="true"/>
                        <as:Attribute name="partsreturn" makeOptional_1="true"/>
                        <as:Attribute name="partskitID" makeOptional_1="true"/>
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                        <as:Element name="PartNumberBase" makeMandatory="true"/>
                        <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                        <as:Element name="Quantity" makeMandatory="true"/>
                        <as:Element name="SaleAmount" makeMandatory="true"/>
                        <as:Element name="DealerCostAmount" makeMandatory="true"/>
                        <as:Element name="Description" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-6" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="PartsInventoryQOHDaily" makeRepeatable="//ERROR/PartsInventoryQOHDaily" makeOptional_2="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Attribute name="currentFileDate" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="InventoryDate" makeMandatory="true">
                            <as:Attribute name="truncInventoryDate" makeMandatory="true"/>
                        </as:Element>
                        <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                        <as:Element name="PartNumberBase" makeMandatory="true"/>
                        <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                        <as:Element name="QuantityOnHand" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-7" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="UsedVehicleSales" makeMandatory="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Attribute name="currentFileDate" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="UsedVehicleInvoiceNumber" makeMandatory="true"/>
                        <as:Element name="SaleDate" makeMandatory="true"/>
                        <as:Element name="SaleType" makeMandatory="true"/>
                        <as:Element name="FILECONTROL17-5" makeMandatory="true"/>
                        <as:Element name="SalesPersonLocalID" makeMandatory="true"/>
                        <as:Element name="SalesPersonNationalID" makeMandatory="true"/>
                        <as:Element name="SoldVIN" makeMandatory="true"/>
                        <as:Element name="SoldOdometerReading" makeMandatory="true"/>
                        <as:Element name="SoldOdometerIndicator" makeMandatory="true"/>
                        <as:Element name="TradeInVIN" makeMandatory="true"/>
                        <as:Element name="TradeInOdometerReading" makeMandatory="true"/>
                        <as:Element name="TradeInOdometerIndicator" makeMandatory="true"/>
                        <as:Element name="CustomerNumber" makeMandatory="true"/>
                        <as:Element name="CustomerContactFlag" makeMandatory="true"/>
                        <as:Element name="FirstName" makeMandatory="true"/>
                        <as:Element name="MiddleInitial" makeMandatory="true"/>
                        <as:Element name="LastName" makeMandatory="true"/>
                        <as:Element name="Title" makeMandatory="true"/>
                        <as:Element name="AddressLine1" makeMandatory="true"/>
                        <as:Element name="AddressLine2" makeMandatory="true"/>
                        <as:Element name="City" makeMandatory="true"/>
                        <as:Element name="StateOrProvince" makeMandatory="true"/>
                        <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                        <as:Element name="HomePhone" makeMandatory="true"/>
                        <as:Element name="WorkPhone" makeMandatory="true"/>
                        <as:Element name="CustomerEmail1" makeMandatory="true"/>
                        <as:Element name="CustomerEmail2" makeMandatory="true"/>
                        <as:Element name="ContractType" makeMandatory="true"/>
                        <as:Element name="SaleTypeDescription" makeMandatory="true"/>
                        <as:Element name="InventoryType" makeMandatory="true"/>
                        <as:Element name="CellPhone" makeMandatory="true"/>
                        <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-10" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="PartsInitialQuantity" makeMandatory="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Attribute name="currentFileDate" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="QuantityDate" makeMandatory="true"/>
                        <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                        <as:Element name="PartNumberBase" makeMandatory="true"/>
                        <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                        <as:Element name="QuantityOnHand" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-0" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-1" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-2" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-3" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-4" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-5" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-6" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-7" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-8" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-9" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-10" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-11" makeMandatory="true"/>
                        <as:Element name="SaleQuantitiyCurrentMonth-12" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-9" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="FileTrailer" makeRepeatable="//ERROR/FileTrailer" makeOptional_2="true">
                        <as:Attribute name="lineNumber" makeMandatory="true"/>
                        <as:Attribute name="lineLength" makeMandatory="true"/>
                        <as:Element name="RecordType" makeMandatory="true"/>
                        <as:Element name="FILECONTROL18" makeMandatory="true"/>
                        <as:Element name="PACode" makeMandatory="true"/>
                        <as:Element name="SubDealerPACode" makeMandatory="true"/>
                        <as:Element name="GeographicSalesAreaCode" makeMandatory="true"/>
                        <as:Element name="FileDate" makeMandatory="true"/>
                        <as:Element name="FileNumber" makeMandatory="true"/>
                        <as:Element name="RecordCount" makeMandatory="true"/>
                        <as:Element name="FileTypeFlag" makeMandatory="true"/>
                        <as:Element name="FILECONTROL16-8" makeMandatory="true"/>
                    </as:Element>
                </as:Element>
                <as:Element name="FileHeader" makeOptional_1="true"
                            printMessage_2="The File Type Flag must be either D (daily) or H (history).?not(./FileTypeFlag[matches(.,'^[DH]$')])"
                            printMessage_3="The Ford Sub-dealer Parts and Accessories Code in the File Header Record must be an alpha-numeric value.?string(normalize-space(./SubDealerPACode)) and not(./SubDealerPACode[matches(normalize-space(.),'^[0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$')])"
                            printMessage_4="The File Number in positions (98-99) of the File Header Record (number of the current file in process) must be a 2 digit numeric value greater than 0.?not(./FileNumber-2[matches(.,'^0[1-9]|[1-9][0-9]$')])"
                            printMessage_5="The VendorID (as assigned by the CDS Analyst) must be a 6 character alpha-numeric value.?not(./VendorID[matches(.,'^[0-9A-Za-z]{6}$')])"
                            printMessage_6="The File Date (date the file was created) in positions (92-97) of the File Header Record must be a valid date in the format MMDDYY.?not(./FileDate-2[matches(.,'^((((0[13578]|1[02])(0[1-9]|[12]\d|3[01])|(0[13456789]|1[012])(0[1-9]|[12]\d|30)|02(0[1-9]|1\d|2[0-8]))\d{2})|0229([02468][048]|[13579][26]))$')])"
                            printMessage_7="The Ford Parts and Accessories Code in the File Header Record must be a 5 character alpha-numeric value.?not(./PACode[matches(.,'^[0-9A-Za-z]{5}$')])"
                            printMessage_8="The dealer Geographic Sales Area Code in the File Header Record (23-28)             (as defined by the Franchise Agreement) must be an alpha-numeric value.?not(./GeographicSalesAreaCode[matches(normalize-space(.),'^[0-9A-Za-z]$|^[0-9A-Za-z][0-9A-Za-z]$|^[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]$')])"
                            printMessage_9="The Franchise Code in positions (132-133) of the File Header Record must be from the enumerated list.?string(normalize-space(./FranchiseCode)) and (not(normalize-space(./FranchiseCode) = '1' or normalize-space(./FranchiseCode) = '3' or ./FranchiseCode = '11' or ./FranchiseCode = '14' or normalize-space(./FranchiseCode) = 'A' or ./FranchiseCode = 'LR' or ./FranchiseCode = 'MA' or normalize-space(./FranchiseCode) = 'U'))"
                            printMessage_10="The DSP Software Release Version (DSP internal software release number) is a required field.?not(string(normalize-space(./DSPSoftwareReleaseVersion)))"
                            printMessage_11="The Record Count in the File Header Record (total number of records submitted) must be an 8 digit numeric value greater than 2.?not(./RecordCount[matches(.,'^[0-9]{8}$')])"
                            printMessage_12="The File Date (date the file was created) in positions (51-56) of the File Header Record must be a valid date in the format MMDDYY.?not(./FileDate[matches(.,'^((((0[13578]|1[02])(0[1-9]|[12]\d|3[01])|(0[13456789]|1[012])(0[1-9]|[12]\d|30)|02(0[1-9]|1\d|2[0-8]))\d{2})|0229([02468][048]|[13579][26]))$')])"
                            printMessage_13="The File Number in positions (57-58) of the File Header Record (number of the current file in process) must be a 2 digit numeric value greater than 0.?not(./FileNumber[matches(.,'^0[1-9]|[1-9][0-9]$')])">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="PACode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL01" makeMandatory="true"/>
                    <as:Element name="FILECONTROL02" makeMandatory="true"/>
                    <as:Element name="FILECONTROL03" makeMandatory="true"/>
                    <as:Element name="FILECONTROL04" makeMandatory="true"/>
                    <as:Element name="FileDate" makeMandatory="true"/>
                    <as:Element name="FileNumber" makeMandatory="true"/>
                    <as:Element name="FILECONTROL05" makeMandatory="true"/>
                    <as:Element name="FILECONTROL06" makeMandatory="true"/>
                    <as:Element name="FILECONTROL05-2" makeMandatory="true"/>
                    <as:Element name="FILECONTROL07" makeMandatory="true"/>
                    <as:Element name="FILECONTROL08" makeMandatory="true"/>
                    <as:Element name="FileDate-2" makeMandatory="true"/>
                    <as:Element name="FileNumber-2" makeMandatory="true"/>
                    <as:Element name="RecordCount" makeMandatory="true"/>
                    <as:Element name="SubDealerPACode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL09" makeMandatory="true"/>
                    <as:Element name="FILECONTROL10" makeMandatory="true"/>
                    <as:Element name="FILECONTROL11" makeMandatory="true"/>
                    <as:Element name="GeographicSalesAreaCode" makeMandatory="true"/>
                    <as:Element name="FranchiseCode" makeMandatory="true"/>
                    <as:Element name="DSPSoftwareReleaseVersion" makeMandatory="true"/>
                    <as:Element name="FILECONTROL12" makeMandatory="true"/>
                    <as:Element name="FILECONTROL13" makeMandatory="true"/>
                    <as:Element name="FILECONTROL14" makeMandatory="true"/>
                    <as:Element name="FILECONTROL02-2" makeMandatory="true"/>
                    <as:Element name="FILECONTROL15" makeMandatory="true"/>
                    <as:Element name="VendorID" makeMandatory="true"/>
                    <as:Element name="FileTypeFlag" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16" makeMandatory="true"/>
                </as:Element>
                <as:Element name="RepairOrderHeader"
                            printMessage_1="The Net Customer Paid Amount (amount which the customer is expected to pay) in the Repair Order Header Record is invalid.  Only numerals are allowed or a '-' in the first position.?string(./NetCustomerPaidAmount) and not(./NetCustomerPaidAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_2="The RO Close Date (date repair order closed) in the Repair Order Header Record is earlier than the corresponding RO Open Date (date the repair order was opened) in the RO Header Record. ?./ROOpenDate/@truncROOpenDate &gt; ./ROCloseDate/@truncROCloseDate"
                            printMessage_3="The Date Appointment Initiated (date customer contacted dealership for appointment) in the Repair Order Header Record must not be greater than the File Date.?./AppointmentInitiatedDate/@truncApptInitDate &gt; ./@currentFileDate"
                            printMessage_4="The Customer City in the Repair Order Header Record must not contain numbers.?./City[matches(.,'[0-9]')]"
                            printMessage_5="The Repair Order Number in the Repair Order Header Record was either empty or all zeros.  A Repair Order  Number is required.?./RONumber = '0000000000000000'"
                            printMessage_6="The Repair Order Cross-Reference Number in the Repair Order Header Record should be alphanumeric only.?./ROXRef[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./ROXRef,'[') or contains(./ROXRef,']')"
                            printMessage_7="The Customer State or Province in the Repair Order Header Record must not contain numbers.?./StateOrProvince[matches(.,'[0-9]')]"
                            printMessage_8="The Service Customer Type Code (type of customer the service is being performed for) in the Repair Order Header Record is not from the enumerated list.?not(./ServiceCustomerTypeCode[matches(.,'^[DFGIRUBJW]$')])"
                            printMessage_9="The Odometer Indicator (miles or kilometer)  in the Repair Order Header Record must be either M or K.?not(./OdometerIndicator[matches(normalize-space(.),'^[MK]$')])"
                            printMessage_10="The Date Appointment Initiated (date customer contacted dealership for appointment) in the Repair Order Header Record must be a valid date in the format YYYYMMDD.?string(./AppointmentInitiatedDate) and (./AppointmentInitiatedDate[matches(.,'[A-Za-z *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./AppointmentInitiatedDate,'[') or contains(./AppointmentInitiatedDate,']'))"
                            printMessage_11="The Home Phone in the Repair Order Header Record must be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./HomePhone)) and (./HomePhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./HomePhone,'[') or contains(./HomePhone,']'))"
                            printMessage_12="The RO Close Date (date repair order closed) in the Repair Order Header Record must be a valid date in the format YYYYMMDD.?not(./ROCloseDate[matches(normalize-space(.),'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_13="The Middle Initial in the Repair Order Header Record must be an alpha character.?string(normalize-space(./MiddleInitial)) and (./MiddleInitial[matches(.,'[0-9 *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./MiddleInitial,'[') or contains(./MiddleInitial,']'))"
                            printMessage_14="The Customer Country Code in the Repair order Header Record should be alphanumeric.?string(normalize-space(./CustomerCountryCode)) and (normalize-space(./CustomerCountryCode)[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CustomerCountryCode,'[') or contains(./CustomerCountryCode,']'))"
                            printMessage_15="The Appointment Type (method used to initiate an appointment) in the Repair Order Header Record is not from the enumerated list.?not(./AppointmentTypeCode[matches(.,'^[AIPWU]$')])"
                            printMessage_16="The RO Open Date (date repair order opened) in the Repair Order Header Record must not be greater than the File Date.?./ROOpenDate/@truncROOpenDate &gt; ./@currentFileDate"
                            printMessage_17="The VIN in the Repair Order Header Record should be alphanumeric only.?string(normalize-space(./VIN)) and (./VIN[matches(.,'[*,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./VIN,'[') or contains(./VIN,']'))"
                            printMessage_18="The Repair Order Close Time in the Repair Order Header Record is invalid. The correct format is HHMM (HH =00-23, MM = 00-59). ?not(./RepairOrderCloseTime[matches(.,'^(0[0-9]|1[0-9]|2[0-3])([0-5][0-9])$')])"
                            printMessage_19="The Work Phone in the Repair Order Header Record must be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./WorkPhone)) and (./WorkPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./WorkPhone,'[') or contains(./WorkPhone,']'))"
                            printMessage_20="The Odometer Reading in the Repair Order Header record should be numeric only.?not(./OdometerReading[matches(normalize-space(.),'^[0-9]{6}$')])"
                            printMessage_21="The Cell Phone in the Repair Order Header Record must be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./CellPhone)) and (./CellPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./CellPhone,'[') or contains(./CellPhone,']'))"
                            printMessage_22="The RO Open Date (date repair order created) in the Repair Order Header Record must be a valid date in the format YYYYMMDD.?not(./ROOpenDate[matches(normalize-space(.),'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_23="The Tax Amount (amount as it appears on the Repair Order)  in the Repair Order Header Record is invalid.  Only numerals are allowed or a '-' in the first position.?string(./TaxAmount) and not(./TaxAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_24="The Repair Order Open Time in the Repair Order Header Record is invalid. The correct format is HHMM (HH =00-23, MM = 00-59). ?not(./RepairOrderOpenTime[matches(.,'^(0[0-9]|1[0-9]|2[0-3])([0-5][0-9])$')])"
                            printMessage_25="The Service Writer - National ID in the Repair Order Header Record should be alphanumeric only and contain the Ford Standardized Training And Reporting System (STARS) ID.?string(normalize-space(./ServiceWriterNationalID)) and (./ServiceWriterNationalID[matches(normalize-space(.),'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./ServiceWriterNationalID,'[') or contains(./ServiceWriterNationalID,']'))"
                            printMessage_26="The RO Close Date (date repair order closed) in the Repair Order Header Record must not be greater than the File Date.?./ROCloseDate/@truncROCloseDate &gt; ./@currentFileDate"
                            printMessage_27="Customer email must be a valid email address.?string(normalize-space(./CustomerEmail)) and not(./CustomerEmail[matches(normalize-space(.),'@')]) and not(./CustomerEmail[matches(normalize-space(.),'\.')])"
                            printMessage_28="The Repair Order Number in the Repair Order Header Record should be alphanumeric only?./RONumber[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./RONumber,'[') or contains(./RONumber,']')"
                            makeRepeatable="//UDBFile/RepairOrderHeader" makeOptional_30="true">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Attribute name="currentFileDate" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="VIN" makeMandatory="true"/>
                    <as:Element name="RONumber" makeMandatory="true"/>
                    <as:Element name="ROXRef" makeMandatory="true"/>
                    <as:Element name="FILECONTROL17" makeMandatory="true"/>
                    <as:Element name="ROOpenDate" makeMandatory="true">
                        <as:Attribute name="truncROOpenDate" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="ROCloseDate" makeMandatory="true">
                        <as:Attribute name="truncROCloseDate" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="OdometerReading" makeMandatory="true"/>
                    <as:Element name="OdometerIndicator" makeMandatory="true"/>
                    <as:Element name="FirstName" makeMandatory="true"/>
                    <as:Element name="MiddleInitial" makeMandatory="true"/>
                    <as:Element name="LastName" makeMandatory="true"/>
                    <as:Element name="Title" makeMandatory="true"/>
                    <as:Element name="AddressLine1" makeMandatory="true"/>
                    <as:Element name="AddressLine2" makeMandatory="true"/>
                    <as:Element name="City" makeMandatory="true"/>
                    <as:Element name="StateOrProvince" makeMandatory="true"/>
                    <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                    <as:Element name="HomePhone" makeMandatory="true"/>
                    <as:Element name="WorkPhone" makeMandatory="true"/>
                    <as:Element name="NetCustomerPaidAmount" makeMandatory="true"/>
                    <as:Element name="TaxAmount" makeMandatory="true"/>
                    <as:Element name="LicensePlateNumber" makeMandatory="true"/>
                    <as:Element name="RepairOrderOpenTime" makeMandatory="true"/>
                    <as:Element name="RepairOrderCloseTime" makeMandatory="true"/>
                    <as:Element name="AppointmentTypeCode" makeMandatory="true"/>
                    <as:Element name="AppointmentInitiatedDate" makeMandatory="true">
                        <as:Attribute name="truncApptInitDate" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="ServiceCustomerTypeCode" makeMandatory="true"/>
                    <as:Element name="ServiceWriterLocalID" makeMandatory="true"/>
                    <as:Element name="ServiceWriterNationalID" makeMandatory="true"/>
                    <as:Element name="CustomerEmail" makeMandatory="true"/>
                    <as:Element name="CellPhone" makeMandatory="true"/>
                    <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-2" makeMandatory="true"/>
                </as:Element>
                <as:Element name="RepairOrderService" makeRepeatable="//UDBFile/RepairOrderService" makeOptional_2="true"
                            printMessage_3="Sublet / Miscellaneous #10 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription10)) and ./SubletOrMiscAmount10 = 0) or             (not(./SubletOrMiscAmount10 = 0) and not(string(normalize-space(./SubletOrMiscDescription10))))"
                            printMessage_4="Sublet / Miscellaneous #2 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription02)) and ./SubletOrMiscAmount02 = 0) or             (not(./SubletOrMiscAmount02 = 0) and not(string(normalize-space(./SubletOrMiscDescription02))))"
                            printMessage_5="Sublet / Miscellaneous #7 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription07)) and ./SubletOrMiscAmount07 = 0) or             (not(./SubletOrMiscAmount07 = 0) and not(string(normalize-space(./SubletOrMiscDescription07))))"
                            printMessage_6="Sublet / Miscellaneous #5 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription05)) and ./SubletOrMiscAmount05 = 0) or             (not(./SubletOrMiscAmount05 = 0) and not(string(normalize-space(./SubletOrMiscDescription05))))"
                            printMessage_7="Sublet / Miscellaneous #8 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription08)) and ./SubletOrMiscAmount08 = 0) or             (not(./SubletOrMiscAmount08 = 0) and not(string(normalize-space(./SubletOrMiscDescription08))))"
                            printMessage_8="Sublet / Miscellaneous #4 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription04)) and ./SubletOrMiscAmount04 = 0) or             (not(./SubletOrMiscAmount04 = 0) and not(string(normalize-space(./SubletOrMiscDescription04))))"
                            printMessage_9="Sublet / Miscellaneous #3 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription03)) and ./SubletOrMiscAmount03 = 0) or             (not(./SubletOrMiscAmount03 = 0) and not(string(normalize-space(./SubletOrMiscDescription03))))"
                            printMessage_10="Sublet / Miscellaneous #9 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription09)) and ./SubletOrMiscAmount09 = 0) or             (not(./SubletOrMiscAmount09 = 0) and not(string(normalize-space(./SubletOrMiscDescription09))))"
                            printMessage_11="Sublet / Miscellaneous Descriptions and Amounts must start at number 1 and be sent in order without skipping numbers.?             (string(normalize-space(./SubletOrMiscDescription02)) and not(string(normalize-space(./SubletOrMiscDescription01)))) or             (string(normalize-space(./SubletOrMiscDescription03)) and not(string(normalize-space(./SubletOrMiscDescription02)))) or             (string(normalize-space(./SubletOrMiscDescription04)) and not(string(normalize-space(./SubletOrMiscDescription03)))) or             (string(normalize-space(./SubletOrMiscDescription05)) and not(string(normalize-space(./SubletOrMiscDescription04)))) or             (string(normalize-space(./SubletOrMiscDescription05)) and not(string(normalize-space(./SubletOrMiscDescription05)))) or             (string(normalize-space(./SubletOrMiscDescription07)) and not(string(normalize-space(./SubletOrMiscDescription06)))) or             (string(normalize-space(./SubletOrMiscDescription08)) and not(string(normalize-space(./SubletOrMiscDescription07)))) or             (string(normalize-space(./SubletOrMiscDescription09)) and not(string(normalize-space(./SubletOrMiscDescription08)))) or             (string(normalize-space(./SubletOrMiscDescription10)) and not(string(normalize-space(./SubletOrMiscDescription09))))"
                            printMessage_12="Sublet / Miscellaneous #1 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription01)) and ./SubletOrMiscAmount01 = 0) or             (not(./SubletOrMiscAmount01 = 0) and not(string(normalize-space(./SubletOrMiscDescription01))))"
                            printMessage_13="Sublet / Miscellaneous #6 must have both a Description and an Amount.?             (string(normalize-space(./SubletOrMiscDescription06)) and ./SubletOrMiscAmount06 = 0) or             (not(./SubletOrMiscAmount06 = 0) and not(string(normalize-space(./SubletOrMiscDescription06))))"
                            printMessage_14="The Sublet Misc. Amount #6 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount06[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_15="The Billed Hours in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./BilledHours[matches(.,'^[-0-9][0-9]{3}$')])"
                            printMessage_16="The Technician - National ID in the Repair Order Service Record should be alphanumeric only and contain the Ford Standardized Training And Reporting System (STARS) ID.?string(normalize-space(./TechnicianNationalID)) and (./TechnicianNationalID[matches(normalize-space(.),'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./TechnicianNationalID,'[') or contains(./TechnicianNationalID,']'))"
                            printMessage_17="The Sequence Number (used with Bundled and Sub Labor Operations) must be a 2 digit numeric value.?not(./SequenceNumber[matches(.,'^[0-9][0-9]$')])"
                            printMessage_18=" The Part cannot both be a parts kit and menu pricing.?string(normalize-space(@partskit)) and string(normalize-space(@menuprice))"
                            printMessage_19="The Repair Type Code (type of customer the service is being performed for) in the Repair Order Service Record is not from the enumerated list.?not(./RepairTypeCode[matches(.,'^[ACEIUW]$')])"
                            printMessage_20="WARNING: Unusually high hours billed.?./BilledHours &gt; 99"
                            printMessage_21="The Servicing Department Code in Repair Order Service Record is not from the enumerated list.?not(./ServicingDepartmentCode[matches(.,'^[BDOQSUM]$')])"
                            printMessage_22="The Sublet Misc. Amount #7 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount07[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_23="The Sublet Misc. Amount #9 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount09[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_24="The Sublet Misc. Amount #5 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount05[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_25="The Sublet Misc. Amount #4 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount04[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_26="The Sublet Misc. Amount #2 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount02[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_27="The Sublet Misc. Amount #10 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount10[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_28="The Labor Charge (amount charged for this service as it appears on the Repair Order) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./LaborChargeAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_29=" The Service cannot both be bundled labor operation and menu pricing.?string(normalize-space(@blonumber)) and string(normalize-space(@menuprice))"
                            printMessage_30="The Sublet Misc. Amount #8 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount08[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_31="The Sublet Misc. Amount #3 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount03[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_32="The Sublet Misc. Amount #1 (dollar amount associated with its description) in the Repair Order Service Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SubletOrMiscAmount01[matches(.,'^[-0-9][0-9]{13}$')])">
                    <as:Attribute name="awaID" makeOptional_1="true"/>
                    <as:Attribute name="bundledlaborID" makeOptional_1="true"/>
                    <as:Attribute name="menupriceID" makeOptional_1="true"/>
                    <as:Attribute name="espwarrantydeductible" makeOptional_1="true"/>
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="SequenceNumber" makeMandatory="true"/>
                    <as:Element name="RepairTypeCode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL17-2" makeMandatory="true"/>
                    <as:Element name="ServicingDepartmentCode" makeMandatory="true"/>
                    <as:Element name="LaborOperationCode" makeMandatory="true"/>
                    <as:Element name="LaborChargeAmount" makeMandatory="true"/>
                    <as:Element name="BilledHours" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription01" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription02" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription03" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription04" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription05" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription06" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription07" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription08" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription09" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscDescription10" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount01" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount02" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount03" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount04" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount05" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount06" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount07" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount08" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount09" makeMandatory="true"/>
                    <as:Element name="SubletOrMiscAmount10" makeMandatory="true"/>
                    <as:Element name="LaborDescription"
                                printMessage_1=" The AWA Labor Description is missing SPLIT NN-NN-NN wording?not(./LaborDescriptionText[matches(.,'.*SPLIT.\d\d-\d\d-\d\d.*')]) and string(normalize-space(./IsAWASplit))='1'"
                                printMessage_2=" The RepairOrderService AWA split between ford dealer and customer does not total 100%.?(number(normalize-space(./AWAFordPercentage)) + number(normalize-space(./AWADealerPercentage)) + number(normalize-space(./AWACustomerPercentage))!=100)             and string(normalize-space(./IsAWASplit))='1'">
                        <as:Element name="IsAWASplit" makeMandatory="true"/>
                        <as:Element name="AWAFordPercentage" makeNillable_1="true"/>
                        <as:Element name="AWADealerPercentage" makeNillable_1="true"/>
                        <as:Element name="AWACustomerPercentage" makeNillable_1="true"/>
                        <as:Element name="LaborDescriptionText" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="TechnicianLocalID" makeMandatory="true"/>
                    <as:Element name="TechnicianNationalID" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-3" makeMandatory="true"/>
                </as:Element>
                <as:Element name="RepairOrderPart"
                            printMessage_1="WARNING: The Part Sale Price should be greater than or equal to the Dealer Part Cost.?not(abs(./SaleAmount) &gt; (abs(./DealerCostAmount) - 1))"
                            printMessage_2="The  Dealer Cost Amount (dealer cost for a single part) in the Repair Order Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./DealerCostAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_3="The Part Quantity in the Repair Order Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./Quantity[matches(.,'^[-0-9][0-9]{3}$')])"
                            printMessage_4="Parts Prefix Part Base and Part Suffix in the Repair Order Part Record are all empty.  A Part Number is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and not(string(normalize-space(./PartNumberSuffix)))"
                            printMessage_5="The Part Causal Code must be alphanumeric.?string(normalize-space(./CausalCode)) and (./CausalCode[matches(normalize-space(.),'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CausalCode,'[') or contains(./CausalCode,']'))"
                            printMessage_6="If Parts Prefix and Part Suffix are sent in the Repair Order Part Record the Part Base is required.?string(normalize-space(./PartNumberPrefix)) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_7="The Part Person - National ID in the Repair Order Part Record should be alphanumeric only and contain the Ford Standardized Training And Reporting System (STARS) ID.?string(normalize-space(./CounterPersonNationalID)) and (./CounterPersonNationalID[matches(normalize-space(.),'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CounterPersonNationalID,'[') or contains(./CounterPersonNationalID,']'))"
                            printMessage_8="If Part Suffix is sent in the Repair Order Part Record the Part Base is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_9="The Sale Amount (extended part price) in the Repair Order Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            makeOptional_10="true" makeRepeatable="//UDBFile/RepairOrderPart">
                    <as:Attribute name="awaID" makeOptional_1="true"/>
                    <as:Attribute name="bundledlaborID" makeOptional_1="true"/>
                    <as:Attribute name="partcoresaleID" makeOptional_1="true"/>
                    <as:Attribute name="partsreturn" makeOptional_1="true"/>
                    <as:Attribute name="partskitID" makeOptional_1="true"/>
                    <as:Attribute name="menupriceID" makeOptional_1="true"/>
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                    <as:Element name="PartNumberBase" makeMandatory="true"/>
                    <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                    <as:Element name="Quantity" makeMandatory="true"/>
                    <as:Element name="SaleAmount" makeMandatory="true"/>
                    <as:Element name="DealerCostAmount" makeMandatory="true"/>
                    <as:Element name="Description"
                                printMessage_1=" The AWA Part Description is missing SPLIT NN-NN-NN wording?not(./DescriptionText[matches(.,'.*SPLIT.\d\d-\d\d-\d\d.*')]) and string(normalize-space(./IsAWASplit))='1'"
                                printMessage_2=" The RepairOrderPart AWA split between ford dealer and customer does not total 100%.?(number(normalize-space(./AWAFordPercentage)) + number(normalize-space(./AWADealerPercentage)) + number(normalize-space(./AWACustomerPercentage))!=100)             and string(normalize-space(./IsAWASplit))='1'">
                        <as:Element name="IsAWASplit" makeMandatory="true"/>
                        <as:Element name="AWAFordPercentage" makeOptional_1="true" makeNillable_2="true"/>
                        <as:Element name="AWADealerPercentage" makeNillable_1="true" makeOptional_2="true"/>
                        <as:Element name="AWACustomerPercentage" makeNillable_1="true" makeOptional_2="true"/>
                        <as:Element name="DescriptionText" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="CausalCode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL17-3" makeMandatory="true"/>
                    <as:Element name="CounterPersonLocalID" makeMandatory="true"/>
                    <as:Element name="CounterPersonNationalID" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-4" makeMandatory="true"/>
                </as:Element>
                <as:Element name="OTCPartInvoiceHeader"
                            printMessage_1="The Parts Customer Type Code (type of customer that purchased the part(s)) in the OTC Header Record is not from the enumerated list.?not(./CustomerTypeCode[matches(.,'^[DFGIRWUBJ]$')])"
                            printMessage_2="The Tax Amount (amount as it appears on the Parts Invoice)  in the OTC Header Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./TaxAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_3="The Invoice Date (date invoice was opened) in the OTC Header Record must not be greater than the File Date.?./InvoiceDate/@truncInvoiceDate &gt; ./@currentFileDate"
                            printMessage_4="The Customer State or Province in the OTC Header Record must not contain numbers.?./StateOrProvince[matches(.,'[0-9]')]"
                            printMessage_5="Customer email must be a valid email address.?string(normalize-space(./CustomerEmail)) and not(./CustomerEmail[matches(normalize-space(.),'@')]) and not(./CustomerEmail[matches(normalize-space(.),'\.')])"
                            printMessage_6="The Invoice Date (date invoice was opened) in the OTC Header Record must be a valid date in the format YYYYMMDD.?not(./InvoiceDate[matches(.,'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_7="The Part Person - National ID in the OTC Header Record should be alphanumeric only and contain the Ford Standardized Training And Reporting System (STARS) ID.?string(normalize-space(./CounterPersonNationalID)) and (./CounterPersonNationalID[matches(normalize-space(.),'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CounterPersonNationalID,'[') or contains(./CounterPersonNationalID,']'))"
                            printMessage_8="The Work Phone in the Repair Order Header Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./WorkPhone)) and (./WorkPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./WorkPhone,'[') or contains(./WorkPhone,']'))"
                            printMessage_9="The Customer Country Code in the OTC Record should be alphanumeric.?string(normalize-space(./CustomerCountryCode)) and (normalize-space(./CustomerCountryCode)[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CustomerCountryCode,'[') or contains(./CustomerCountryCode,']'))"
                            printMessage_10="The Middle Initial in the OTC Part Invoice Header must be an alpha character.?string(normalize-space(./MiddleInitial)) and (./MiddleInitial[matches(.,'[0-9 *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./MiddleInitial,'[') or contains(./MiddleInitial,']'))"
                            printMessage_11="The Invoice Number in the OTC Header Record was either empty or all zeros.  An Invoice Number is required.?not(string(normalize-space(./InvoiceNumber)))"
                            printMessage_12="The Customer Identification Code in the OTC Header Record was empty. This field is required if the Parts Customer Type Code is either 'D' 'F' 'G' or 'W'.?not(string(normalize-space(./CustomerTaxID))) and ./CustomerTypeCode[matches(.,'^[DFGW]$')]"
                            printMessage_13="The Shipping Amount (amount charged for transporting the part to the customer)  in the OTC Header Record is invalid.  Only numerals are allowed or a '-' in the first position.?string(normalize-space(./ShippingAmount)) and not(./ShippingAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_14="The Home Phone in the Repair Order Header Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./HomePhone)) and (./HomePhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./HomePhone,'[') or contains(./HomePhone,']'))"
                            printMessage_15="The Discount Amount (sum of all discounts for the invoice.)  in the OTC Header Record is invalid.  Only numerals are allowed or a '-' in the first position.?string(normalize-space(./DiscountAmount)) and not(./DiscountAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_16="The Cell Phone in the OTC Header Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./CellPhone)) and (./CellPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./CellPhone,'[') or contains(./CellPhone,']'))"
                            printMessage_17="The Customer City in the OTC Header Record must not contain numbers.?./City[matches(.,'[0-9]')]" makeOptional_18="true"
                            makeRepeatable="//UDBFile/OTCPartInvoiceHeader">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Attribute name="currentFileDate" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="InvoiceNumber" makeMandatory="true"/>
                    <as:Element name="InvoiceDate" makeMandatory="true">
                        <as:Attribute name="truncInvoiceDate" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="LastName" makeMandatory="true"/>
                    <as:Element name="AddressLine1" makeMandatory="true"/>
                    <as:Element name="AddressLine2" makeMandatory="true"/>
                    <as:Element name="City" makeMandatory="true"/>
                    <as:Element name="StateOrProvince" makeMandatory="true"/>
                    <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                    <as:Element name="CustomerTypeCode" makeMandatory="true"/>
                    <as:Element name="CustomerTaxID" makeMandatory="true"/>
                    <as:Element name="TaxAmount" makeMandatory="true"/>
                    <as:Element name="FILECONTROL17-4" makeMandatory="true"/>
                    <as:Element name="CounterPersonLocalID" makeMandatory="true"/>
                    <as:Element name="CounterPersonNationalID" makeMandatory="true"/>
                    <as:Element name="FirstName" makeMandatory="true"/>
                    <as:Element name="MiddleInitial" makeMandatory="true"/>
                    <as:Element name="Title" makeMandatory="true"/>
                    <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                    <as:Element name="HomePhone" makeMandatory="true"/>
                    <as:Element name="WorkPhone" makeMandatory="true"/>
                    <as:Element name="CellPhone" makeMandatory="true"/>
                    <as:Element name="CustomerEmail" makeMandatory="true"/>
                    <as:Element name="DiscountAmount" makeMandatory="true"/>
                    <as:Element name="ShippingAmount" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-5" makeMandatory="true"/>
                </as:Element>
                <as:Element name="OTCPartsInvoicePart"
                            printMessage_1="If Part Suffix is sent in the OTC Parts Invoice Part Record the Part Base is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_2="The Dealer Cost Amount (dealer net cost) in the OTC Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./DealerCostAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_3="If Parts Prefix and Part Suffix are sent in the OTC Parts Invoice Part Record the Part Base is required.?string(normalize-space(./PartNumberPrefix)) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_4="Parts Prefix Part Base and Part Suffix in the OTC Part Record are all empty.  A Part Number is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and not(string(normalize-space(./PartNumberSuffix)))"
                            printMessage_5="WARNING: The Part Sale Price should be greater than or equal to the Part Sale Dealer Cost.?not(abs(./SaleAmount) &gt; (abs(./DealerCostAmount) - 1))"
                            printMessage_6="The Sale Amount (actual unit sale price charged for a single part as it appears on the invoice) in the OTC Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleAmount[matches(.,'^[-0-9][0-9]{13}$')])"
                            printMessage_7="The Part Quantity (quantity of parts as it appears on the OTC Invoice)  in the OTC Part Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./Quantity[matches(.,'^[-0-9][0-9]{3}$')])"
                            makeRepeatable="//UDBFile/OTCPartsInvoicePart" makeOptional_9="true">
                    <as:Attribute name="partcoresaleID" makeOptional_1="true"/>
                    <as:Attribute name="partsreturn" makeOptional_1="true"/>
                    <as:Attribute name="partskitID" makeOptional_1="true"/>
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                    <as:Element name="PartNumberBase" makeMandatory="true"/>
                    <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                    <as:Element name="Quantity" makeMandatory="true"/>
                    <as:Element name="SaleAmount" makeMandatory="true"/>
                    <as:Element name="DealerCostAmount" makeMandatory="true"/>
                    <as:Element name="Description" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-6" makeMandatory="true"/>
                </as:Element>
                <as:Element name="PartsInventoryQOHDaily"
                            printMessage_1="If Part Suffix is sent in the Parts Inventory QOH Daily Record the Part Base is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_2="The Quantity Date (date the quantity is being reported for) in the Parts Inventory Quantity on Hand Record must be a valid date in the format YYYYMMDD.?not(./InventoryDate[matches(.,'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_3="The Quantity Date (date the quantity is being reported for) in the Parts Inventory Quantity on Hand Record must not be greater than the File Date.?./InventoryDate/@truncInventoryDate &gt; ./@currentFileDate"
                            printMessage_4="Parts Prefix Part Base and Part Suffix in the Parts Inventory Quantity on Hand Record are all empty.  A Part Number is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and not(string(normalize-space(./PartNumberSuffix)))"
                            printMessage_5="The Quantity On Hand (count of this part at the end of the daily processing)  in the Parts Inventory Quantity on Hand Record is invalid.  Only numerals are allowed or a '-' in the first position..?not(./QuantityOnHand[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_6="If Parts Prefix and Part Suffix are sent in the Parts Inventory QOH Daily Record the Part Base is required.?string(normalize-space(./PartNumberPrefix)) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            makeRepeatable="//UDBFile/PartsInventoryQOHDaily" makeOptional_8="true">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Attribute name="currentFileDate" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="InventoryDate" makeMandatory="true">
                        <as:Attribute name="truncInventoryDate" makeMandatory="true"/>
                    </as:Element>
                    <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                    <as:Element name="PartNumberBase" makeMandatory="true"/>
                    <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                    <as:Element name="QuantityOnHand" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-7" makeMandatory="true"/>
                </as:Element>
                <as:Element name="UsedVehicleSales"
                            printMessage_1="The Customer City in the Used Vehicle Sales Record must not contain numbers.?./City[matches(.,'[0-9]')]"
                            printMessage_2="Customer email 1 in the Used Vehicle Sales Record must be a valid email address.?string(normalize-space(./CustomerEmail1)) and (not(./CustomerEmail1[matches(normalize-space(.),'@')]) or not(./CustomerEmail1[matches(normalize-space(.),'\.')]))"
                            printMessage_3="The Sale Type in the Used Vehicle Sales Record is required and must contain one of the values 'F' 'R' or 'C'.?not(string(normalize-space(./SaleType))) or not(./SaleType[matches(normalize-space(.),'^[FRC]$')])"
                            printMessage_4="The Sale Type Description in the Used Vehicle Sales Record must be an alpha-numeric value.?string(normalize-space(./SaleTypeDescription)) and (./SaleTypeDescription[matches(.,'[*,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./SaleTypeDescription,'[') or contains(./SaleTypeDescription,']'))"
                            printMessage_5="The Trade In Odometer Indicator (miles or kilometer) in the Used Vehicle Sales Record must be either M or K.?not(./TradeInOdometerIndicator[matches(normalize-space(.),'^[MK]$')])"
                            printMessage_6="The Sale Date (date the used vehicle was sold) in the Used Vehicle Sales Record must be a valid date in the format YYYYMMDD.?not(./SaleDate[matches(.,'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_7="The Sold Odometer Indicator (miles or kilometer) in the Used Vehicle Sales Record must be either M or K.?not(./SoldOdometerIndicator[matches(normalize-space(.),'^[MK]$')])"
                            printMessage_8="The Customer State or Province in the Used Vehicle Sales Record must not contain numbers.?./StateOrProvince[matches(.,'[0-9]')]"
                            printMessage_9="The Home Phone in the Used Vehicle Sales Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./HomePhone)) and (./HomePhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./HomePhone,'[') or contains(./HomePhone,']'))"
                            printMessage_10="The Contract Type in the Used Vehicle Sales Record must be an alpha-numeric value.?string(normalize-space(./ContractType)) and (./ContractType[matches(.,'[*,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./ContractType,'[') or contains(./ContractType,']'))"
                            printMessage_11="The Inventory Type in the Used Vehicle Sales Record must be an alpha value.?string(normalize-space(./InventoryType)) and (./InventoryType[matches(.,'[0-9*,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./InventoryType,'[') or contains(./InventoryType,']'))"
                            printMessage_12="Customer email 2 in the Used Vehicle Sales Record must be a valid email address.?string(normalize-space(./CustomerEmail2)) and (not(./CustomerEmail2[matches(normalize-space(.),'@')]) or not(./CustomerEmail2[matches(normalize-space(.),'\.')]))"
                            printMessage_13="The Customer Contact Flag in the Used Vehicle Sales Record must contain one of the values 'Y' 'N' or 'U'.?not(./CustomerContactFlag[matches(normalize-space(.),'^[YNU]$')])"
                            printMessage_14="The Middle Initial in the Used Vehicle Sales Record must be an alpha character.?string(normalize-space(./MiddleInitial)) and (./MiddleInitial[matches(.,'[0-9 *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./MiddleInitial,'[') or contains(./MiddleInitial,']'))"
                            printMessage_15="The Trade In Odometer Reading in the Used Vehicle Sales record should be numeric only.?not(./TradeInOdometerReading[matches(normalize-space(.),'^[0-9]{6}$')])"
                            printMessage_16="The Sold VIN in the Used Vehicle Sales Record should be alphanumeric only.?string(normalize-space(./SoldVIN)) and (./SoldVIN[matches(.,'[*,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./SoldVIN,'[') or contains(./SoldVIN,']'))"
                            printMessage_17="The Customer Country Code in the Used Vehicle Sales Record should be alpha-numeric.?string(normalize-space(./CustomerCountryCode)) and (normalize-space(./CustomerCountryCode)[matches(.,'[ *,.;:=+\-_?#$%@\^\\/!&gt;|}{()]')] or contains(./CustomerCountryCode,'[') or contains(./CustomerCountryCode,']'))"
                            printMessage_18="The Cell Phone in the Used Vehicle Sales Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./CellPhone)) and (./CellPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./CellPhone,'[') or contains(./CellPhone,']'))"
                            printMessage_19="The Sold Odometer Reading in the Used Vehicle Sales record should be numeric only.?not(./SoldOdometerReading[matches(normalize-space(.),'^[0-9]{6}$')])"
                            printMessage_20="The Work Phone in the Used Vehicle Sales Record should be numeric only. Do NOT fill in extra spaces with zeros.?string(normalize-space(./WorkPhone)) and (./WorkPhone[matches(.,'[A-Za-z*,;\-:=+_?#$%@\^\\/!&gt;|}{]')] or contains(./WorkPhone,'[') or contains(./WorkPhone,']'))">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Attribute name="currentFileDate" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="UsedVehicleInvoiceNumber" makeMandatory="true"/>
                    <as:Element name="SaleDate" makeMandatory="true"/>
                    <as:Element name="SaleType" makeMandatory="true"/>
                    <as:Element name="FILECONTROL17-5" makeMandatory="true"/>
                    <as:Element name="SalesPersonLocalID" makeMandatory="true"/>
                    <as:Element name="SalesPersonNationalID" makeMandatory="true"/>
                    <as:Element name="SoldVIN" makeMandatory="true"/>
                    <as:Element name="SoldOdometerReading" makeMandatory="true"/>
                    <as:Element name="SoldOdometerIndicator" makeMandatory="true"/>
                    <as:Element name="TradeInVIN" makeMandatory="true"/>
                    <as:Element name="TradeInOdometerReading" makeMandatory="true"/>
                    <as:Element name="TradeInOdometerIndicator" makeMandatory="true"/>
                    <as:Element name="CustomerNumber" makeMandatory="true"/>
                    <as:Element name="CustomerContactFlag" makeMandatory="true"/>
                    <as:Element name="FirstName" makeMandatory="true"/>
                    <as:Element name="MiddleInitial" makeMandatory="true"/>
                    <as:Element name="LastName" makeMandatory="true"/>
                    <as:Element name="Title" makeMandatory="true"/>
                    <as:Element name="AddressLine1" makeMandatory="true"/>
                    <as:Element name="AddressLine2" makeMandatory="true"/>
                    <as:Element name="City" makeMandatory="true"/>
                    <as:Element name="StateOrProvince" makeMandatory="true"/>
                    <as:Element name="ZipOrPostalCode" makeMandatory="true"/>
                    <as:Element name="HomePhone" makeMandatory="true"/>
                    <as:Element name="WorkPhone" makeMandatory="true"/>
                    <as:Element name="CustomerEmail1" makeMandatory="true"/>
                    <as:Element name="CustomerEmail2" makeMandatory="true"/>
                    <as:Element name="ContractType" makeMandatory="true"/>
                    <as:Element name="SaleTypeDescription" makeMandatory="true"/>
                    <as:Element name="InventoryType" makeMandatory="true"/>
                    <as:Element name="CellPhone" makeMandatory="true"/>
                    <as:Element name="CustomerCountryCode" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-10" makeMandatory="true"/>
                </as:Element>
                <as:Element name="PartsInitialQuantity"
                            printMessage_1="Parts Prefix Part Base and Part Suffix in the Parts Initial Quantity Record are all empty.  A Part Number is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and not(string(normalize-space(./PartNumberSuffix)))"
                            printMessage_2="The Quantity Sold 7 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-7[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_3="The Quantity Sold 12 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-12[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_4="The Quantity Sold 2 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-2[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_5="The Quantity Date (date the quantity is being reported for) in the Parts Initial Quantity Record must be a valid date in the format YYYYMMDD.?not(./QuantityDate[matches(.,'^([2-9]\d{3}((0[1-9]|1[012])(0[1-9]|1\d|2[0-8])|(0[13456789]|1[012])(29|30)|(0[13578]|1[02])31)|(([2-9]\d)(0[48]|[2468][048]|[13579][26])|(([2468][048]|[3579][26])00))0229)$')])"
                            printMessage_6="The Quantity Sold 11 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-11[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_7="The Quantity Sold 5 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-5[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_8="The Quantity Sold 4 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-4[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_9="If Parts Prefix and Part Suffix are sent in the Parts Initial Quantity Record the Part Base is required.?string(normalize-space(./PartNumberPrefix)) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_10="The Quantity Sold 10 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-10[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_11="The Quantity Sold Last Month in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-1[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_12="The Quantity Sold Current Month in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-0[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_13="If Part Suffix is sent in the Parts Initial Quantity Record the Part Base is required.?not(string(normalize-space(./PartNumberPrefix))) and not(string(normalize-space(./PartNumberBase))) and string(normalize-space(./PartNumberSuffix))"
                            printMessage_14="The Quantity Sold 6 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-6[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_15="The Quantity On Hand (count of this part at the end of the daily processing) in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./QuantityOnHand[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_16="The Quantity Sold 3 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-3[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_17="The Quantity Sold 9 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-9[matches(.,'^[-0-9][0-9]{6}$')])"
                            printMessage_18="The Quantity Sold 8 Months Ago in the Parts Initial Quantity Record is invalid.  Only numerals are allowed or a '-' in the first position.?not(./SaleQuantitiyCurrentMonth-8[matches(.,'^[-0-9][0-9]{6}$')])">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Attribute name="currentFileDate" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="QuantityDate" makeMandatory="true"/>
                    <as:Element name="PartNumberPrefix" makeMandatory="true"/>
                    <as:Element name="PartNumberBase" makeMandatory="true"/>
                    <as:Element name="PartNumberSuffix" makeMandatory="true"/>
                    <as:Element name="QuantityOnHand" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-0" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-1" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-2" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-3" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-4" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-5" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-6" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-7" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-8" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-9" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-10" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-11" makeMandatory="true"/>
                    <as:Element name="SaleQuantitiyCurrentMonth-12" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-9" makeMandatory="true"/>
                </as:Element>
                <as:Element name="FileTrailer" makeOptional_1="true"
                            printMessage_2="The dealer Geographic Sales Area Code in the File Trailer (as defined by the Franchise Agreement) must be an alpha-numeric value.?not(./GeographicSalesAreaCode[matches(normalize-space(.),'^[0-9A-Za-z]$|^[0-9A-Za-z][0-9A-Za-z]$|^[0-9A-Za-z][0-9A-Za-z][0-9A-Za-z]$')])"
                            printMessage_3="File Type Flag in position 39 of the Trailer Record must be from the enumerated list.?not(./FileTypeFlag[matches(.,'^[DH]$')])"
                            printMessage_4="The File Date (date the file was created) in positions (23-28) of the File Trailer Record must be a valid date in the format MMDDYY.?not(./FileDate[matches(.,'^((((0[13578]|1[02])(0[1-9]|[12]\d|3[01])|(0[13456789]|1[012])(0[1-9]|[12]\d|30)|02(0[1-9]|1\d|2[0-8]))\d{2})|0229([02468][048]|[13579][26]))$')])"
                            printMessage_5="The Ford Sub-dealer Parts and Accessories Code in the File Trailer must be an alpha-numeric value.?string(normalize-space(./SubDealerPACode)) and not(./SubDealerPACode[matches(normalize-space(.),'^[0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$|^[0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z][0-9a-zA-Z]$')])"
                            printMessage_6="The Record Count in the File Trailer (total number of records submitted) must be a 8 digit numeric value greater than 2.?not(./RecordCount[matches(.,'^[0-9]{8}$')])"
                            printMessage_7="The File Number in positions (29-30) of the File Trailer (number of the current file in process) must be a 2 digit numeric value greater than 0.?not(./FileNumber[matches(.,'^0[1-9]|[1-9][0-9]$')])"
                            printMessage_8="The Ford Parts and Accessories Code in the File Trailer must be a 5 character alpha-numeric value.?not(./PACode[matches(.,'^[0-9A-Za-z]{5}$')])">
                    <as:Attribute name="lineNumber" makeMandatory="true"/>
                    <as:Attribute name="lineLength" makeMandatory="true"/>
                    <as:Element name="RecordType" makeMandatory="true"/>
                    <as:Element name="FILECONTROL18" makeMandatory="true"/>
                    <as:Element name="PACode" makeMandatory="true"/>
                    <as:Element name="SubDealerPACode" makeMandatory="true"/>
                    <as:Element name="GeographicSalesAreaCode" makeMandatory="true"/>
                    <as:Element name="FileDate" makeMandatory="true"/>
                    <as:Element name="FileNumber" makeMandatory="true"/>
                    <as:Element name="RecordCount" makeMandatory="true"/>
                    <as:Element name="FileTypeFlag" makeMandatory="true"/>
                    <as:Element name="FILECONTROL16-8" makeMandatory="true"/>
                </as:Element>
            </as:Element>
        </as:Structure>
    </as:AssemblyStructure>
</as:CAM>