# CS 255 Project Two Client Presentation

## DriverPass System Design

Roderick L. Hughey  
CS 255: System Analysis and Design

This file preserves the final client-facing presentation content and speaker notes in a GitHub-friendly format.

---

## Slide 1: DriverPass System Design

**A secure system for learning, practice exams, lesson scheduling, and reporting.**

Speaker notes: No speaker notes required for this slide.

---

## Slide 2: System Requirements

### Functional Requirements

- Account creation and package enrollment
- Online course and practice exam access
- Conflict-free driving lesson scheduling
- Progress tracking, lesson notes, and reports

### Nonfunctional Requirements

- 200 customer sessions and 25 staff sessions at launch
- 95% of normal pages load in under 3 seconds
- Schedule checks finish in under 2 seconds
- 99.5% monthly uptime target

Bottom line: one central system, fewer schedule mistakes, and clearer training progress.

### Speaker Notes

This slide summarizes the most important needs the system must meet. Students need to create accounts, choose a package, complete online training, take practice exams, schedule lessons, and view their progress. DriverPass staff need to manage records, schedules, lesson notes, and reports from one place. The measurable targets keep the design practical: pages should load quickly, schedule checks should happen fast, the system should support launch traffic, and downtime should stay limited.

---

## Slide 3: Use Case Diagram

The design separates student, office, instructor, management, and IT work so each group gets the tools it needs without seeing everything.

### Speaker Notes

This diagram shows who uses the system and what each group needs to do. Students use it for accounts, training, practice exams, lessons, and progress. Office staff use it to help customers and manage schedules. Instructors use it to view lessons and record notes. Management uses it for content and reports. IT uses it to manage access and system settings. This keeps DriverPass organized because each group gets the right tools without giving everyone access to everything.

---

## Slide 4: Activity Diagram

### Schedule Driving Appointment

- First, the system confirms the student still has lesson time in the selected package.
- Next, it checks that the student, instructor, vehicle, and time slot are all available.
- Only confirmed appointments are saved and sent to the student and staff.
- This protects DriverPass from double-booking and keeps the schedule reliable.

### Speaker Notes

This slide breaks down the lesson scheduling process. A student or staff member starts by opening the schedule. The system first checks whether the student still has lesson time available in the selected package. Then it checks whether the instructor, vehicle, and time are open. If anything does not work, the user is sent back to choose another option. A lesson is saved only after the details are confirmed. That meets DriverPass needs by reducing schedule mistakes and preventing two people from claiming the same appointment slot.

---

## Slide 5: Security

Security is built around access, protection, and traceability.

- **Separate sign-in:** Each person signs in with an individual account.
- **Limited access:** Students, instructors, staff, management, and IT only see what they need.
- **Protected records:** Student data, schedules, lesson notes, and reports are protected while stored and when shared.
- **Extra checks:** Accounts that can make major system changes require an additional identity check.
- **Activity history:** Important changes are logged so DriverPass can review what happened if something looks wrong.
- **Sign-in protection:** Five failed sign-in attempts within 15 minutes trigger a lock or review.

### Speaker Notes

Security is handled in plain business terms: people sign in separately, only see the information they need, and sensitive records are protected. Important changes are logged so DriverPass can trace what happened later if needed. Accounts with the power to change system settings require an extra identity check. This protects student information and helps DriverPass keep control of daily operations.

---

## Slide 6: System Limitations

The first release is focused on the highest-value business needs.

- No full offline editing for official records
- No native iOS or Android app in the first release
- Direct DMV integration depends on outside access and rules
- Payments, SMS, email tools, and maps may require separate services
- Major customer growth may require scaling after launch
- DriverPass must approve content and package rules before release

These limits protect the timeline while leaving room for future upgrades.

### Speaker Notes

The first version intentionally focuses on the highest-value work: training, practice exams, scheduling, progress, lesson notes, and reporting. Some features are better saved for later, such as full offline editing, native mobile apps, payment processing, text reminders, maps, and direct DMV connections. Calling out these limits helps DriverPass launch faster while keeping a clear path for future upgrades.
