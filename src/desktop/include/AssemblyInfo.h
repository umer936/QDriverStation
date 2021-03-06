/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _QDS_ASSEMBLY_INFO_H
#define _QDS_ASSEMBLY_INFO_H

#include <QString>
#include <QObject>

/**
 * @class AssemblyInfo
 * @brief Provides application details
 *
 * The \c AssemblyInfo class provides details about the application.
 * For example, it provides its name and version.
 *
 * The class was implemented to ease the process of changing the details of
 * the application, such as its name ('Open DriverStation' is not so brilliant)
 * and its version information.
 */
class AssemblyInfo
{
public:
    /**
     * Returns the name of the application
     */
    static QString name();

    /**
     * Returns the version of the application
     */
    static QString version();

    /**
     * Returns the name of the company that develops the app
     */
    static QString organization();

    /**
     * Returns the date and time when the program was compiled
     */
    static QString buildDateTime();
};

#endif /* _QDS_ASSEMBLY_INFO_H */
