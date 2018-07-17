/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:54:02 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 17:30:35 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include <sys/mman.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <mach-o/loader.h>
# include <stdio.h>

void						line_put(char *filename);
int							find_magic_number(unsigned char *content);
void						usage(void);
void						*dynamic_lib_read(void *content, size_t size);
int							endswith(char *str, char *end);
void						nm_so(unsigned char *content, size_t size,
							void (*symbols)(void *, int flag), char *filepath);
void						print_mem_val(unsigned long long hex);
int							hex_number_length(size_t number);
void						intro_info(char *filename);
int							is_dynamic_lib(unsigned char *content);
int							read_file(void **content, size_t *size,
							char *filename);
void						otool(void *content, int flag);
int							is_64_or_32(struct mach_header *head);
struct segment_command_64	*iterate_to_textseg(
							struct load_command *comm,
							int command_num,
							size_t count);
void						print_hex_value(unsigned long long hex);
void						put_otool_hex(unsigned long long hex);
void						print_mem_val(unsigned long long hex);
void						otool_32(struct mach_header *header, void *content,
						int flag);
void						otool_64(struct mach_header *header, void *content,
						int flag);
void						print_section(void *content,
							size_t start, size_t limit, size_t size);
unsigned char				*print_obj_name(unsigned char *content,
						size_t size);
unsigned char				*find_first_label_seg(unsigned char *content,
						size_t size);
unsigned char				*exit_header(unsigned char *content,
						size_t size);
unsigned char				*leave_header(unsigned char *content,
						size_t size);
int							start_frame(unsigned char *content, size_t size);
unsigned char				*find_stack_frame(unsigned char *content,
						size_t size);
unsigned char				*reverse_to_next_frame(unsigned char *content);
int							signature_check(unsigned char *content);
int							arc_magic(unsigned char *content);

#endif
