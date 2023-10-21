/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_FS_FS_SYS_H_
#define ZEPHYR_INCLUDE_FS_FS_SYS_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup file_system_api
 * @{
 */

/**
 * @brief File System interface structure
<<<<<<< HEAD
 *
 * @param open Opens or creates a file, depending on flags given
 * @param read Reads nbytes number of bytes
 * @param write Writes nbytes number of bytes
 * @param lseek Moves the file position to a new location in the file
 * @param tell Retrieves the current position in the file
 * @param truncate Truncates/expands the file to the new length
 * @param sync Flushes the cache of an open file
 * @param close Flushes the associated stream and closes the file
 * @param opendir Opens an existing directory specified by the path
 * @param readdir Reads directory entries of an open directory
 * @param closedir Closes an open directory
 * @param mount Mounts a file system
 * @param unmount Unmounts a file system
 * @param unlink Deletes the specified file or directory
 * @param rename Renames a file or directory
 * @param mkdir Creates a new directory using specified path
 * @param stat Checks the status of a file or directory specified by the path
 * @param statvfs Returns the total and available space on the file system
 *        volume
 * @param mkfs Formats a device to specified file system type. Note that this
 *        operation destroys existing data on a target device.
 */
struct fs_file_system_t {
	/* File operations */
	int (*open)(struct fs_file_t *filp, const char *fs_path,
		    fs_mode_t flags);
	ssize_t (*read)(struct fs_file_t *filp, void *dest, size_t nbytes);
	ssize_t (*write)(struct fs_file_t *filp,
					const void *src, size_t nbytes);
	int (*lseek)(struct fs_file_t *filp, off_t off, int whence);
	off_t (*tell)(struct fs_file_t *filp);
	int (*truncate)(struct fs_file_t *filp, off_t length);
	int (*sync)(struct fs_file_t *filp);
	int (*close)(struct fs_file_t *filp);
	/* Directory operations */
	int (*opendir)(struct fs_dir_t *dirp, const char *fs_path);
	int (*readdir)(struct fs_dir_t *dirp, struct fs_dirent *entry);
	int (*closedir)(struct fs_dir_t *dirp);
	/* File system level operations */
	int (*mount)(struct fs_mount_t *mountp);
	int (*unmount)(struct fs_mount_t *mountp);
	int (*unlink)(struct fs_mount_t *mountp, const char *name);
	int (*rename)(struct fs_mount_t *mountp, const char *from,
					const char *to);
	int (*mkdir)(struct fs_mount_t *mountp, const char *name);
	int (*stat)(struct fs_mount_t *mountp, const char *path,
					struct fs_dirent *entry);
	int (*statvfs)(struct fs_mount_t *mountp, const char *path,
					struct fs_statvfs *stat);
#if defined(CONFIG_FILE_SYSTEM_MKFS)
	int (*mkfs)(uintptr_t dev_id, void *cfg, int flags);
#endif
=======
 */
struct fs_file_system_t {
	/**
	 * @name File operations
	 * @{
	 */
	/**
	 * Opens or creates a file, depending on flags given.
	 *
	 * @param filp File to open/create.
	 * @param fs_path Path to the file.
	 * @param flags Flags for opening/creating the file.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*open)(struct fs_file_t *filp, const char *fs_path,
		    fs_mode_t flags);
	/**
	 * Reads nbytes number of bytes.
	 *
	 * @param filp File to read from.
	 * @param dest Destination buffer.
	 * @param nbytes Number of bytes to read.
	 * @return Number of bytes read on success, negative errno code on fail.
	 */
	ssize_t (*read)(struct fs_file_t *filp, void *dest, size_t nbytes);
	/**
	 * Writes nbytes number of bytes.
	 *
	 * @param filp File to write to.
	 * @param src Source buffer.
	 * @param nbytes Number of bytes to write.
	 * @return Number of bytes written on success, negative errno code on fail.
	 */
	ssize_t (*write)(struct fs_file_t *filp,
					const void *src, size_t nbytes);
	/**
	 * Moves the file position to a new location in the file.
	 *
	 * @param filp File to move.
	 * @param off Relative offset from the position specified by whence.
	 * @param whence Position in the file. Possible values: SEEK_CUR, SEEK_SET, SEEK_END.
	 * @return New position in the file or negative errno code on fail.
	 */
	int (*lseek)(struct fs_file_t *filp, off_t off, int whence);
	/**
	 * Retrieves the current position in the file.
	 *
	 * @param filp File to get the current position from.
	 * @return Current position in the file or negative errno code on fail.
	 */
	off_t (*tell)(struct fs_file_t *filp);
	/**
	 * Truncates/expands the file to the new length.
	 *
	 * @param filp File to truncate/expand.
	 * @param length New length of the file.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*truncate)(struct fs_file_t *filp, off_t length);
	/**
	 * Flushes the cache of an open file.
	 *
	 * @param filp File to flush.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*sync)(struct fs_file_t *filp);
	/**
	 * Flushes the associated stream and closes the file.
	 *
	 * @param filp File to close.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*close)(struct fs_file_t *filp);
	/** @} */

	/**
	 * @name Directory operations
	 * @{
	 */
	/**
	 * Opens an existing directory specified by the path.
	 *
	 * @param dirp Directory to open.
	 * @param fs_path Path to the directory.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*opendir)(struct fs_dir_t *dirp, const char *fs_path);
	/**
	 * Reads directory entries of an open directory.
	 *
	 * @param dirp Directory to read from.
	 * @param entry Next directory entry in the dirp directory.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*readdir)(struct fs_dir_t *dirp, struct fs_dirent *entry);
	/**
	 * Closes an open directory.
	 *
	 * @param dirp Directory to close.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*closedir)(struct fs_dir_t *dirp);
	/** @} */

	/**
	 * @name File system level operations
	 * @{
	 */
	/**
	 * Mounts a file system.
	 *
	 * @param mountp Mount point.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*mount)(struct fs_mount_t *mountp);
	/**
	 * Unmounts a file system.
	 *
	 * @param mountp Mount point.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*unmount)(struct fs_mount_t *mountp);
	/**
	 * Deletes the specified file or directory.
	 *
	 * @param mountp Mount point.
	 * @param name Path to the file or directory to delete.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*unlink)(struct fs_mount_t *mountp, const char *name);
	/**
	 * Renames a file or directory.
	 *
	 * @param mountp Mount point.
	 * @param from Path to the file or directory to rename.
	 * @param to New name of the file or directory.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*rename)(struct fs_mount_t *mountp, const char *from,
					const char *to);
	/**
	 * Creates a new directory using specified path.
	 *
	 * @param mountp Mount point.
	 * @param name Path to the directory to create.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*mkdir)(struct fs_mount_t *mountp, const char *name);
	/**
	 * Checks the status of a file or directory specified by the path.
	 *
	 * @param mountp Mount point.
	 * @param path Path to the file or directory.
	 * @param entry Directory entry.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*stat)(struct fs_mount_t *mountp, const char *path,
					struct fs_dirent *entry);
	/**
	 * Returns the total and available space on the file system volume.
	 *
	 * @param mountp Mount point.
	 * @param path Path to the file or directory.
	 * @param stat File system statistics.
	 * @return 0 on success, negative errno code on fail.
	 */
	int (*statvfs)(struct fs_mount_t *mountp, const char *path,
					struct fs_statvfs *stat);
#if defined(CONFIG_FILE_SYSTEM_MKFS) || defined(__DOXYGEN__)
	/**
	 * Formats a device to specified file system type.
	 * Available only if @kconfig{CONFIG_FILE_SYSTEM_MKFS} is enabled.
	 *
	 * @param dev_id Device identifier.
	 * @param cfg File system configuration.
	 * @param flags Formatting flags.
	 * @return 0 on success, negative errno code on fail.
	 *
	 * @note This operation destroys existing data on the target device.
	 */
	int (*mkfs)(uintptr_t dev_id, void *cfg, int flags);
#endif
	/** @} */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_FS_FS_SYS_H_ */
