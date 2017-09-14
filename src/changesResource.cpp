//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "changes/changesResource.h"

changesResource::changesResource() {

}

changesResource::changesResource(const string &kind, const string &type, time_t datetime, bool removed,
                                 const string &fileId, const filesResource &file, const string &teamDriveId,
                                 const teamdrivesResource &teamDrive) : kind(kind), type(type), datetime(datetime),
                                                                        removed(removed), fileId(fileId), file(file),
                                                                        teamDriveId(teamDriveId),
                                                                        teamDrive(teamDrive) {}
