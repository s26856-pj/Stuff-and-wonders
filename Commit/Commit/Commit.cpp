#include <iostream>
#include <unistd.h>
#include <ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <UserNotifications/UserNotifications.h>

void przypomnij_o_commit() {
    
    CFStringRef notificationTitle = CFStringCreateWithCString(NULL, "Przypomnienie o commicie", kCFStringEncodingUTF8);
    CFStringRef notificationBody = CFStringCreateWithCString(NULL, "Klaudia Słońce, zrób commit!", kCFStringEncodingUTF8);

    // Tworzymy obiekt powiadomienia
    CFUserNotificationRef userNotification = CFUserNotificationCreate(
        NULL,               // allocator
        0,                  // timeout (0 - brak timeoutu)
        kCFUserNotificationNoteAlertLevel, // styl powiadomienia
        NULL,               
        notificationTitle, 
        notificationBody,
        NULL                
    );

  
    CFOptionFlags response;
    CFUserNotificationReceiveResponse(userNotification, 0, &response);

    
    CFRelease(notificationTitle);
    CFRelease(notificationBody);
    CFRelease(userNotification);
}

int main() {
    
    unsigned int czas_przypomnienia = 10 * 60;

    while (true) {
        sleep(czas_przypomnienia);
        przypomnij_o_commit();
    }

    return 0;
}
