# binternal-loader
How multibox works?
- Suspending all opened growtopia window
- Resetting mutex
- The growtopia will be created with CreatProcessA
- Find opened growtopia HWND using the processID
- Synchronize (waiting for response)
- Disabling growtopia mutex
- Setting up mutex so the growtopia still think the mutex is exists
- Set prohibit dynamic code to false
- Restore NTDLL
- Inject DLL
- Resume all opened Growtopia window


How to use?
- First prompt: how many Growtopia window do you want to open?
- Second prompt: find the .dll you want to inject
- Wait for a few seconds and boom! its done.
