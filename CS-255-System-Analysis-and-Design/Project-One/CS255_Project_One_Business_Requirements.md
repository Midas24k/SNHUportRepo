# CS 255 Business Requirements Document

## DriverPass System

Roderick L. Hughey

## System Components and Design

### Purpose

- The purpose of the project is to design one secure, web-based system that allows DriverPass to deliver online driver education, practice exams, and on-the-road lesson scheduling from a central source.
- DriverPass is the client. Owner Liam and IT officer Ian need the system to support students, the secretary, driving instructors, administrators, IT staff, and management without relying on separate spreadsheets or disconnected records.
- The design should help students prepare with current learning material and practical instruction instead of depending only on previously released test questions.
- The completed design will become the foundation for development, testing, deployment, and later system expansion.

### System Background

- DriverPass identified a business opportunity after finding that more than 65% of applicants fail the driving-license exam when their preparation is limited to studying old tests.
- The proposed system will combine account registration, training-package selection, online course access, practice testing, appointment scheduling, instructor and vehicle assignment, lesson notes, progress tracking, and management reporting.
- Students will use the system to study and manage services. The secretary will support customers by phone or in person. Instructors will review assignments and record lesson comments. Management will review reports, and the IT officer will maintain users, permissions, content, logs, and configuration.
- DriverPass wants browser access from computers and mobile devices. Reports may be downloaded for offline review, but official records must remain in the centralized system to avoid conflicting copies and duplicate updates.
- The initial operation includes ten vehicles and a trainer associated with each vehicle, so the scheduling component must treat students, instructors, vehicles, and time slots as limited resources.

### Objectives and Goals

- Create a complete user-account and role structure for students, the secretary, instructors, administrators, the owner, and the IT officer.
- Allow a student or secretary to create, change, or cancel an eligible appointment while preventing 100% of confirmed double-bookings involving a student, instructor, vehicle, or time slot.
- Track every practice-test attempt by test name, start and completion time, score, and status, including not started, in progress, failed, or passed.
- Track every driving lesson by date, start time, end time, assigned instructor, assigned vehicle, package hours used, package hours remaining, and instructor comments.
- Enforce the three defined training packages: Package One provides six hours of behind-the-wheel training; Package Two provides eight hours plus an in-person DMV rules lesson; Package Three provides twelve hours, the in-person lesson, and online class and practice-test access.
- Provide authorized management users with on-screen reports and downloadable data while limiting each employee to the information required by that role.
- Complete modeling, customer approval, interface development, database integration, business logic, testing, delivery, and client sign-off according to the schedule shown in the Gantt chart.

## Requirements

### Nonfunctional Requirements

#### Performance Requirements

- The production system should support at least 200 concurrent customer sessions and 25 concurrent employee or administrator sessions without a redesign.
- At least 95% of standard page requests, including login, dashboard, course, practice-test, schedule, and report pages, should complete within three seconds under the expected load.
- Appointment availability checks and confirmed schedule changes should complete within two seconds, and the database must lock the affected resources during the transaction so a second user cannot reserve the same slot.
- Practice-test submissions, profile updates, lesson notes, and other record changes should return a success or error confirmation within two seconds after the server receives the request.
- The system should provide at least 99.5% monthly availability, excluding announced maintenance, which limits unplanned downtime to approximately three hours and forty minutes in a 30-day month.
- Planned maintenance should not exceed two hours per month and should be announced to staff and customers at least 48 hours in advance whenever possible.
- Incremental backups should run at least every 15 minutes, a full backup should run nightly, and restoration procedures should target a recovery point of 15 minutes and a recovery time of four hours.
- Authorized staff should be able to publish approved DMV content and practice-question updates without rebuilding or redeploying the entire application.

#### Platform Constraints

- The first release will be a responsive web application rather than a separate Windows, macOS, iOS, or Android installation.
- The interface should support the current and immediately previous major versions of Chrome, Edge, Firefox, and Safari on Windows, macOS, iOS, Android, and ChromeOS.
- The layout should remain usable from a 360-pixel mobile viewport through a 1920-pixel desktop viewport without hiding required functions.
- The back end should use a centralized relational database for accounts, roles, packages, appointments, vehicles, instructors, lesson records, practice tests, test attempts, content, and reports.
- All record changes must pass through authenticated server-side services or APIs. Downloaded spreadsheets or reports are read-only copies and cannot replace the official database record.
- Direct connections to DMV services, payment processors, text messaging, email delivery, or mapping services are outside the base platform unless DriverPass approves the additional integration work.

#### Accuracy and Precision

- Each person and business record should have a unique internal identifier. Usernames and email addresses should be matched without regard to capitalization, while passwords remain case-sensitive.
- The system should validate required fields, email format, phone format, date and time values, package eligibility, available package hours, and test completion before saving a record.
- The scheduling engine must use one atomic transaction to verify and reserve the student, instructor, vehicle, and time slot. A conflicting request must fail with a clear explanation instead of partially saving.
- Appointment and lesson timestamps should be stored to the nearest minute. Package time should be calculated to the nearest quarter hour, and practice-test scores should be stored to at least one decimal place before display rounding.
- Reports should be generated from the centralized database and show the date and time the report was produced so users can distinguish current results from downloaded copies.
- The system should alert the IT officer within five minutes when a backup fails, an administrative update fails, repeated scheduling conflicts occur, or an application error prevents a required business function.

#### Adaptability

- Authorized administrators should be able to add, deactivate, or modify users and role assignments through the interface without changing source code.
- Training packages, included services, lesson lengths, instructors, vehicles, operating hours, blocked dates, practice tests, and course content should be stored as configurable data rather than hard-coded values.
- The system should use separate interface, business-logic, and data-access layers so a change to one area does not force a complete redesign of the others.
- The interface should use standards-based responsive design and be regression-tested when supported browsers or operating systems release major updates.
- The IT officer should have elevated but auditable access to configuration, account support, content maintenance, logs, backup status, and system health. Routine business users should not receive those permissions.
- Future capabilities such as payment processing, appointment reminders, DMV data feeds, additional branches, or a native mobile app should be addable through new modules or integrations.

#### Security

- Every user must authenticate with a unique account. Passwords should contain at least 12 characters and be stored with a modern salted, adaptive hash rather than readable encryption.
- All browser-to-server and service-to-service traffic containing credentials or DriverPass records should use HTTPS with TLS 1.2 or later.
- Role-based access control must follow least privilege. Students may view only their own records, instructors may view assigned lessons, the secretary may manage customer and scheduling data, and administrative functions must be limited to authorized personnel.
- Privileged accounts, including owner, administrator, and IT accounts, should use multifactor authentication.
- Five failed sign-in attempts within 15 minutes should trigger a 15-minute account lock or equivalent risk-based protection. Repeated events should create an alert for the IT officer.
- Inactive sessions should expire after 30 minutes for staff and administrators. Sensitive actions such as permission changes should require recent authentication.
- Password-reset links should be single-use, expire within 30 minutes, and be sent only after the account identifier is verified without revealing whether an email address exists in the system.
- Audit records should capture sign-ins, failed sign-ins, password resets, permission changes, user changes, schedule changes, content changes, report exports, and other privileged actions. Security logs should be retained for at least 12 months.

### Functional Requirements

- The system shall allow a new customer to create an account with required identity and contact information.
- The system shall validate user credentials during login and apply permissions based on the authenticated user role.
- The system shall allow a customer to view and update permitted profile and contact information.
- The system shall allow the secretary to create or update a customer record for a caller or walk-in customer.
- The system shall display each DriverPass training package and the services included with that package.
- The system shall enroll a customer in the selected training package and record package hours and service eligibility.
- The system shall provide online class content only to customers whose package includes that content.
- The system shall provide practice exams only to customers whose package includes practice-exam access.
- The system shall record each practice-test attempt, including the test name, start time, completion time, score, and current status.
- The system shall display practice-test results and progress to the correct customer and authorized staff.
- The system shall display available driving-lesson dates and times based on customer eligibility, instructor availability, vehicle availability, and business hours.
- The system shall allow an eligible customer to schedule, modify, or cancel a driving appointment online.
- The system shall allow the secretary to schedule, modify, or cancel an appointment for an eligible customer.
- The system shall assign an available instructor and vehicle to each confirmed driving appointment.
- The system shall prevent overlapping appointments for the same customer, instructor, vehicle, or time slot.
- The system shall prevent a customer from scheduling more training time than remains in the selected package.
- The system shall track each lesson date, start time, end time, assigned instructor, assigned vehicle, hours used, and remaining package hours.
- The system shall allow an instructor to view assigned lessons and enter comments after a lesson.
- The system shall allow authorized administrators to manage users, roles, training packages, instructors, vehicles, operating hours, and schedule availability.
- The system shall allow authorized administrators to add, revise, publish, or retire online course content and practice-test questions.
- The system shall allow the owner and authorized administrators to generate reports by customer, appointment, instructor, vehicle, package, test result, or date range.
- The system shall allow authorized users to download approved report data in a common spreadsheet format for offline review.
- The system shall provide a secure password-reset process for users who cannot access their accounts.
- The system shall record important authentication, administrative, content, scheduling, and reporting actions in an audit log.
- The system shall display clear confirmation or error messages after a user submits a form or attempts an unavailable action.

### User Interface

- Customers need a dashboard that shows the selected package, remaining training hours, online content, practice tests, results, upcoming lessons, cancellations, and lesson comments that are approved for customer viewing.
- The secretary needs a fast staff workspace for customer lookup, new-customer entry, contact updates, package review, schedule search, and appointment creation or changes while speaking with a customer.
- Instructors need a mobile-friendly daily schedule that identifies the customer, lesson time, assigned vehicle, and a form for lesson completion and comments.
- The owner and administrators need dashboards for business reports, user and role management, packages, instructors, vehicles, scheduling controls, course content, and practice tests.
- The IT officer needs a restricted administration area for system configuration, account support, logs, backup status, content maintenance, and troubleshooting.
- The interface should use consistent navigation, plain labels, keyboard access, readable contrast, descriptive validation messages, and confirmation dialogs for destructive actions. Student-facing and employee-facing pages should target WCAG 2.2 Level AA accessibility.
- The responsive interface should provide the same required business functions through supported desktop, tablet, and mobile browsers, although layouts may rearrange for smaller screens.

### Assumptions

- Students and employees have reliable internet access, an email address, and a device with a supported modern browser.
- DriverPass will supply and approve package descriptions, pricing, DMV rules, online lessons, practice questions, passing criteria, operating hours, cancellation rules, and reporting definitions.
- The first launch will support the ten vehicles and associated trainers described by DriverPass, but administrators may add more without code changes.
- DriverPass will identify which instructor comments are visible to students and which are restricted to employees or management.
- Official data changes require an online connection. Downloaded reports may be reviewed offline but will not synchronize edits back into the system.
- The interview did not fully define payment processing, so package enrollment and payment confirmation can be designed as separate functions until DriverPass selects a provider and approves scope.
- DriverPass will provide email or identity-service accounts needed for password reset, multifactor authentication, and system notifications.

### Limitations

- The first release will not support full offline data entry or synchronization because duplicate and conflicting records would increase system complexity and risk.
- A native mobile application is outside the first-release scope. Mobile access will be provided through responsive web pages.
- Direct DMV integration depends on external access, data-sharing rules, interface documentation, and approval that DriverPass does not control.
- Payment processing, text-message reminders, mapping, and commercial email delivery may require outside vendors, transaction fees, contracts, and separate security reviews.
- The schedule depends on timely customer approval, access to final content, clear business rules, and availability of assigned project personnel.
- The initial performance targets assume the defined launch capacity. Large expansion to multiple locations or thousands of simultaneous users may require additional hosting, database, and network resources.
- No online service can guarantee uninterrupted access. Local internet outages, cloud-provider failures, maintenance, cyber incidents, or third-party outages may temporarily reduce availability.

## Gantt Chart and Schedule Detail

The schedule prioritizes requirements and modeling before development, allows selected modeling tasks to overlap, places customer approval before interface construction, and reserves testing for the point when the interface, database, and business logic are connected.

| Task | Owner | Start | Finish | Dependency |
|---|---|---:|---:|---|
| Collect requirements | Sam & Jennifer | Jan 22 | Feb 4 | Project kickoff |
| Create use case diagrams | Sam & Jennifer | Feb 11 | Feb 18 | Requirements complete |
| Build activity diagrams | Toni & Clark | Feb 15 | Mar 9 | Use cases drafted |
| Research user interface designs | John | Feb 27 | Mar 7 | Requirements complete |
| Build class diagram | Sam & Jennifer | Mar 1 | Mar 9 | Use cases drafted |
| Customer review and approval | All stakeholders | Mar 10 | Mar 11 | Models complete |
| Build interface | John | Mar 12 | Mar 24 | Customer approval |
| Link database to interface | Toni & Clark | Mar 24 | Apr 3 | Interface started |
| Add business logic layer | Toni, Clark & John | Apr 5 | Apr 27 | Database linked |
| Test system | All project team | Apr 27 | May 7 | Business logic complete |
| System delivery | All project team | May 8 | May 8 | Testing complete |
| Sign-off meeting | Client & project team | May 9 | May 10 | Delivery complete |
