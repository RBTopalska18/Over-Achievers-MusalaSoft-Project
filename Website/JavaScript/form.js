function formsubmit() {
	//get all form data
	var name = document.getElementById("contactForm").elements["name"].value;
	var subject = document.getElementById("contactForm").elements["subject"].value;
	var type = document.getElementById("contactForm").elements["type"].value;
	var bodytext = document.getElementById("contactForm").elements["bodytext"].value;

	//generate mailto href
	var mailtohref = "mailto:demo@quarantineactivities.bg?";
	mailtohref += "subject=" + type + ": " + subject;
	mailtohref += "&body=" + escape(bodytext) + escape("\n\n    - ") + name;

	document.getElementById("mailLink").href = mailtohref;

	document.getElementById("mailLink").click();
}
