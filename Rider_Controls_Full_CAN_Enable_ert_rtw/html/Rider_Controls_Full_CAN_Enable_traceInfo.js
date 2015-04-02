function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Rider_Controls_Full_CAN_Enable"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/CAN Pack1"] = {sid: "Rider_Controls_Full_CAN_Enable:90"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:90"] = {rtwname: "<Root>/CAN Pack1"};
	this.rtwnameHashMap["<Root>/InHardware"] = {sid: "Rider_Controls_Full_CAN_Enable:77"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:77"] = {rtwname: "<Root>/InHardware"};
	this.rtwnameHashMap["<Root>/OutHardware"] = {sid: "Rider_Controls_Full_CAN_Enable:84"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:84"] = {rtwname: "<Root>/OutHardware"};
	this.rtwnameHashMap["<Root>/Software"] = {sid: "Rider_Controls_Full_CAN_Enable:55"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:55"] = {rtwname: "<Root>/Software"};
	this.rtwnameHashMap["<Root>/eCAN Transmit1"] = {sid: "Rider_Controls_Full_CAN_Enable:91"};
	this.sidHashMap["Rider_Controls_Full_CAN_Enable:91"] = {rtwname: "<Root>/eCAN Transmit1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
