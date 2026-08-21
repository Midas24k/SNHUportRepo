# CS 255 System Design Document

## DriverPass System

Roderick L. Hughey  
CS 255: System Analysis and Design  
August 16, 2026

## Design Focus

This document turns the DriverPass business needs into a practical system design that developers can use. The design supports online training, practice exams, driving lesson scheduling, lesson notes, progress tracking, reporting, and controlled employee access from one central web-based system.

## System Design Overview

- The system gives students one place to create an account, choose a package, complete online work, schedule lessons, and view progress.
- Secretaries can manage customer records and lesson scheduling without bypassing package limits or vehicle and instructor availability.
- Instructors can review schedules, record lesson results, and provide notes that update the student progress record.
- Management can update training content, review reports, and make informed decisions from centralized records.
- The IT officer can manage accounts, roles, backups, audit logs, and system configuration while protecting student data.

# UML Diagrams

## UML Use Case Diagram

The use case diagram shows the major work that students, staff, management, and IT need to complete in the DriverPass system. It keeps the design tied to actual business needs instead of only showing screens.

```mermaid
flowchart LR
    Student[Student]
    Secretary[Secretary]
    Instructor[Instructor]
    Manager[Owner / Manager]
    IT[IT Officer]

    subgraph DP[DriverPass System]
      Login([Log in / verify identity])
      Account([Create account and select package])
      Materials([Access online training materials])
      Exam([Complete practice exam])
      Progress([View progress and test results])
      Records([Manage customer records])
      Schedule([Schedule driving lesson])
      Modify([Modify or cancel lesson])
      Notes([Record lesson notes])
      Reports([Generate business reports])
      Content([Update training, exam, and DMV content])
      Users([Manage users and security roles])
      Hours([Check package hours])
      Availability([Check instructor and vehicle availability])
      Score([Record exam score])
    end

    Student --> Login
    Student --> Account
    Student --> Materials
    Student --> Exam
    Student --> Progress
    Student --> Schedule
    Student --> Modify

    Secretary --> Login
    Secretary --> Records
    Secretary --> Schedule
    Secretary --> Modify

    Instructor --> Login
    Instructor --> Schedule
    Instructor --> Notes

    Manager --> Login
    Manager --> Reports
    Manager --> Content

    IT --> Login
    IT --> Users
    IT --> Content

    Schedule -. include .-> Hours
    Schedule -. include .-> Availability
    Modify -. include .-> Availability
    Exam -. include .-> Score
```

## UML Activity Diagram: Schedule Driving Appointment

The first activity diagram breaks down the driving lesson scheduling process. The corrected flow prevents a failed package check, scheduling conflict, or declined confirmation from reaching a saved appointment. This matters because DriverPass must avoid double-booking students, instructors, vehicles, and time slots.

```mermaid
flowchart LR
    A((Start)) --> B[Sign in]
    B --> C[Open lesson scheduling]
    C --> D{Package hours remain?}
    D -- No --> E[Show package hours message]
    E --> Z((End))
    D -- Yes --> F[Select date, time, instructor, and vehicle]
    F --> G{Instructor and vehicle available?}
    G -- No --> H[Show conflict and choose another time]
    H --> F
    G -- Yes --> I{Confirm appointment?}
    I -- No --> J[Review lesson details]
    J --> F
    I -- Yes --> K[Save appointment and reserve resources]
    K --> L[Send confirmation to student and staff]
    L --> Z
```

## UML Activity Diagram: Complete Practice Exam

The second activity diagram breaks down the practice exam process. It checks package access before the exam opens, separates saving an attempt from submitting an attempt, records the final score, and updates progress after submission.

```mermaid
flowchart LR
    A((Start)) --> B[Sign in]
    B --> C[Select practice exam]
    C --> D{Package includes practice exams?}
    D -- No --> E[Show package access message]
    E --> Z((End))
    D -- Yes --> F[Load questions and timer]
    F --> G[Answer exam questions]
    G --> H{Submit now?}
    H -- No, finish later --> I[Save attempt as in progress]
    I --> Z
    H -- Yes --> J[Score exam and identify missed topics]
    J --> K[Store score and completed status]
    K --> L[Update progress dashboard]
    L --> M[Display results to student]
    M --> Z
```

## UML Sequence Diagram: Schedule Driving Appointment

The sequence diagram shows the communication needed to schedule a driving appointment. It uses an alternate path to show what happens when the requested time is available and what happens when it is not. This is important because the system must stop two people from reserving the same limited resource at the same time.

```mermaid
sequenceDiagram
    actor User as Student / Secretary
    participant Web as Web App
    participant Account as Account & Package Service
    participant Schedule as Scheduling Service
    participant DB as Database
    participant Notify as Notification Service

    User->>Web: Request lesson scheduling
    Web->>Account: Verify package hours
    Account-->>Web: Eligible or show message
    Web->>Schedule: Request available instructors, vehicles, and times
    Schedule->>DB: Check schedule records
    DB-->>Schedule: Return available options

    alt Appointment available
        Schedule->>DB: Save appointment and reserve resources
        DB-->>Schedule: Appointment saved
        Schedule->>Notify: Send confirmation request
        Notify-->>User: Confirmation sent
    else Appointment unavailable
        Schedule-->>Web: Show conflict and select another time
        Web-->>User: Choose another option
    end
```

## UML Class Diagram

The class diagram shows the main records the system needs and how they connect. It includes the customer, package, practice exam, lesson appointment, instructor, vehicle, lesson record, report, audit, and content update records needed for the proposed DriverPass system.

```mermaid
classDiagram
    class User {
        +userId
        +name
        +email
        +phone
        +passwordHash
        +role
        +accountStatus
    }

    class Customer {
        +customerId
        +dateOfBirth
        +permitNumber
        +registrationDate
    }

    class Employee {
        +employeeId
        +employeeType
        +activeStatus
    }

    class TrainingPackage {
        +packageId
        +name
        +includedServices
        +includedDrivingHours
        +price
    }

    class PackageEnrollment {
        +enrollmentId
        +startDate
        +remainingDrivingHours
        +status
    }

    class TrainingMaterial {
        +materialId
        +title
        +contentType
        +version
        +activeFlag
    }

    class PracticeExam {
        +examId
        +title
        +questionSet
        +activeFlag
    }

    class ExamAttempt {
        +attemptId
        +startTime
        +completionTime
        +score
        +status
    }

    class Instructor {
        +instructorId
        +licenseNumber
        +availabilityStatus
    }

    class Vehicle {
        +vehicleId
        +makeModel
        +plateNumber
        +availabilityStatus
    }

    class DrivingLessonAppointment {
        +appointmentId
        +dateTime
        +duration
        +status
        +confirmationNumber
    }

    class LessonRecord {
        +lessonRecordId
        +skillsPracticed
        +instructorNotes
        +hoursUsed
    }

    class Report {
        +reportId
        +reportType
        +dateRange
        +createdDate
        +createdBy
    }

    class AuditLog {
        +auditId
        +action
        +recordChanged
        +timestamp
        +performedBy
    }

    class DMVUpdate {
        +updateId
        +sourceDate
        +contentSummary
        +postedBy
    }

    User "1" --> "0..1" Customer
    User "1" --> "0..1" Employee
    User "1" --> "0..*" AuditLog
    Customer "1" --> "0..*" PackageEnrollment
    TrainingPackage "1" --> "0..*" PackageEnrollment
    TrainingPackage "1" --> "0..*" TrainingMaterial
    TrainingPackage "1" --> "0..*" PracticeExam
    Customer "1" --> "0..*" ExamAttempt
    PracticeExam "1" --> "0..*" ExamAttempt
    Customer "1" --> "0..*" DrivingLessonAppointment
    Instructor "1" --> "0..*" DrivingLessonAppointment
    Vehicle "1" --> "0..*" DrivingLessonAppointment
    DrivingLessonAppointment "1" --> "0..1" LessonRecord
    Employee "1" --> "0..*" Report
    Employee "1" --> "0..*" DMVUpdate
```

# Technical Requirements

| Area | Technical Requirement | Reason for Requirement |
|---|---|---|
| Hardware | Cloud-hosted web and application servers sized for at least 200 concurrent customer sessions and 25 concurrent staff or administrator sessions. | Supports launch demand and allows growth without rebuilding the system. |
| Hardware | Centralized database server or managed database service for users, packages, schedules, lessons, tests, reports, audit logs, and configuration records. | Keeps official records in one reliable place and prevents conflicting spreadsheets or paper records. |
| Hardware | Encrypted backup storage in a separate availability zone or storage location. | Protects student records, schedule history, lesson notes, and business reports if the main system fails. |
| Software | Responsive web application compatible with current and previous major versions of Chrome, Edge, Firefox, and Safari. | Supports desktops, tablets, and phones without requiring a separate native app for the first release. |
| Software | Server-side business logic for account validation, package eligibility, scheduling, scoring, reporting, and audit logging. | Prevents users from bypassing rules and keeps schedule decisions consistent across screens. |
| Software | Relational database management system with transaction support and indexed schedule, reservation, and account tables. | Prevents double-booked students, instructors, vehicles, and time slots during appointment changes. |
| Tools | UML modeling tool such as Lucidchart for maintaining use case, activity, sequence, and class diagrams. | Gives analysts, developers, and the client a shared picture of the system before implementation. |
| Tools | Version control, issue tracking, automated testing, and controlled deployment tools. | Keeps changes traceable, reduces regressions, and supports safer releases. |
| Infrastructure | HTTPS with TLS 1.2 or later, identity management, role-based access control, and multifactor authentication for privileged accounts. | Protects login credentials and limits access to sensitive business and student information. |
| Infrastructure | Monitoring and alerts for failed backups, repeated login failures, scheduling errors, unavailable services, and critical application failures. | Helps the IT officer respond before small problems become business-stopping issues. |
| Infrastructure | Incremental backups at least every 15 minutes, nightly full backups, a 15-minute recovery point target, and a 4-hour recovery time target. | Limits data loss and downtime after technical failures or mistakes. |
| Infrastructure | 99.5% monthly uptime target excluding announced maintenance, with planned maintenance limited to two hours per month when possible. | Sets a clear reliability expectation while still allowing planned updates. |

## Requirement Traceability Notes

- The account and role design supports students, the secretary, instructors, administrators, the owner, and the IT officer.
- The scheduling design supports package-hour rules and prevents confirmed double-booking for students, instructors, vehicles, and time slots.
- The practice-test design records test name, start time, completion time, score, and status so progress can be reported accurately.
- The reporting design supports on-screen review and downloadable data while official updates stay in the central system.
- First-release limitations remain clear: full offline editing, native mobile apps, direct DMV integration, payment processing, SMS reminders, and mapping can be added later if DriverPass approves the scope.

## Reference

Southern New Hampshire University. (n.d.). *DriverPass interview transcript* [Course document].
