#include <iostream>
#include <string>
#include <curl/curl.h>

int main() {
    std::string targetEmail = "target@example.com";
    std::string fromEmail = "hacker@example.com";
    std::string subject = "Important Information";
    std::string body = "Dear Sir/Madam,\n\nPlease click the following link to access your account information: http://example.com/login\n\nBest regards,\nHacker";

    std::string command = "curl --url 'smtps://smtp.example.com:465' --ssl-reqd --mail-from '" + fromEmail + "' --mail-rcpt '" + targetEmail + "' --user '" + fromEmail + "' --insecure --upload-file - <<EOF\n"
                            "From: " + fromEmail + "\n"
                            "To: " + targetEmail + "\n"
                            "Subject: " + subject + "\n"
                            "\n" + body + "\nEOF";

    system(command.c_str());

    return 0;
}